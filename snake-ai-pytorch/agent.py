from chop.nn.quantized.modules.linear import LinearInteger
from chop.nn.quantizers.quantizers_for_hw import integer_floor_quantizer_for_hw
import torch
import random
import numpy as np
from collections import deque
from game import SnakeGameAI, Direction, Point
from model import Linear_QNet, QTrainer
from helper import plot, plot_2d_weights
import os

MAX_MEMORY = 100_000
BATCH_SIZE = 1000
LR = 0.001

class Agent:

    def __init__(self):
        self.n_games = 0
        self.epsilon = 0 # randomness
        self.gamma = 0.9 # discount rate
        self.memory = deque(maxlen=MAX_MEMORY) # popleft()
        self.model = Linear_QNet(11, 256, 3)
        self.trainer = QTrainer(self.model, lr=LR, gamma=self.gamma)
        # self.model.load_state_dict(torch.load("/Users/thw20/Documents/ichack25/model_grid/model.pth"))


    def get_state(self, game):
        head = game.snake[0]
        point_l = Point(head.x - 20, head.y)
        point_r = Point(head.x + 20, head.y)
        point_u = Point(head.x, head.y - 20)
        point_d = Point(head.x, head.y + 20)
        
        dir_l = game.direction == Direction.LEFT
        dir_r = game.direction == Direction.RIGHT
        dir_u = game.direction == Direction.UP
        dir_d = game.direction == Direction.DOWN

        state = [
            # Danger straight
            (dir_r and game.is_collision(point_r)) or 
            (dir_l and game.is_collision(point_l)) or 
            (dir_u and game.is_collision(point_u)) or 
            (dir_d and game.is_collision(point_d)),

            # Danger right
            (dir_u and game.is_collision(point_r)) or 
            (dir_d and game.is_collision(point_l)) or 
            (dir_l and game.is_collision(point_u)) or 
            (dir_r and game.is_collision(point_d)),

            # Danger left
            (dir_d and game.is_collision(point_r)) or 
            (dir_u and game.is_collision(point_l)) or 
            (dir_r and game.is_collision(point_u)) or 
            (dir_l and game.is_collision(point_d)),
            
            # Move direction
            dir_l,
            dir_r,
            dir_u,
            dir_d,
            
            # Food location 
            game.food.x < game.head.x,  # food left
            game.food.x > game.head.x,  # food right
            game.food.y < game.head.y,  # food up
            game.food.y > game.head.y  # food down
            ]

        return np.array(state, dtype=int)

    def remember(self, state, action, reward, next_state, done):
        self.memory.append((state, action, reward, next_state, done)) # popleft if MAX_MEMORY is reached

    def train_long_memory(self):
        if len(self.memory) > BATCH_SIZE:
            mini_sample = random.sample(self.memory, BATCH_SIZE) # list of tuples
        else:
            mini_sample = self.memory

        states, actions, rewards, next_states, dones = zip(*mini_sample)
        self.trainer.train_step(states, actions, rewards, next_states, dones)
        #for state, action, reward, nexrt_state, done in mini_sample:
        #    self.trainer.train_step(state, action, reward, next_state, done)

    def train_short_memory(self, state, action, reward, next_state, done):
        self.trainer.train_step(state, action, reward, next_state, done)

    def get_action(self, state):
        # random moves: tradeoff exploration / exploitation
        self.epsilon = 20 - self.n_games
        final_move = [0,0,0]
        if random.randint(0, 200) < self.epsilon:
            move = random.randint(0, 2)
            final_move[move] = 1
        else:
            state0 = torch.tensor(state, dtype=torch.float)
            prediction = self.model(state0)
            move = torch.argmax(prediction).item()
            final_move[move] = 1

        return final_move

quan_args = {
    "by": "type",
    "default": {"config": {"name": None}},
    "linear": {
        "config": {
            # "name": "integer",
            # data
            # "data_in_width": 32,
            # "data_in_frac_width": 16,
            # # weight
            # "weight_width": 32,
            # "weight_frac_width": 16,
            # # bias
            # "bias_width": 32,
            # "bias_frac_width": 16,


            # "data_in_width": 8,
            # "data_in_frac_width": 4,
            # # weight
            # "weight_width": 8,
            # "weight_frac_width": 4,
            # # bias
            # "bias_width": 8,
            # "bias_frac_width": 4,
            

            "data_in_width": 4,
            "data_in_frac_width": 2,
            # weight
            "weight_width": 4,
            "weight_frac_width": 2,
            # bias
            "bias_width": 4,
            "bias_frac_width": 2,
            "floor": True

            # "data_in_width": 2,
            # "data_in_frac_width": 1,
            # # weight
            # "weight_width": 2,
            # "weight_frac_width": 1,
            # # bias
            # "bias_width": 2,
            # "bias_frac_width": 1,
            # "floor": True
        }
    },
}


import torch.nn as nn
import torch.nn.functional as F
class Linear_QQNet(nn.Module):
    def __init__(self, input_size, hidden_size, output_size, config):
        super().__init__()
        self.linear1 = LinearInteger(input_size, hidden_size, config=config)
        self.linear2 = LinearInteger(hidden_size, output_size, config=config)

    def forward(self, x):
        x = F.relu(self.linear1(x))
        x = self.linear2(x)
        return x

    def save(self, file_name='model.pth'):
        model_folder_path = './model'
        if not os.path.exists(model_folder_path):
            os.makedirs(model_folder_path)

        file_name = os.path.join(model_folder_path, file_name)
        torch.save(self.state_dict(), file_name)

class Linear_bNet(nn.Module):
    def __init__(self, input_size, hidden_size, output_size, config):
        super().__init__()
        self.linear1 = LinearInteger(input_size, hidden_size, config=config)
        self.linear2 = LinearInteger(hidden_size, hidden_size, config=config)
        self.linear3 = LinearInteger(hidden_size, output_size, config=config)

    def forward(self, x):
        x = F.relu(self.linear1(x))
        x = F.relu(self.linear2(x))
        x = self.linear3(x)
        return x

    def save(self, file_name='model.pth'):
        model_folder_path = './model'
        if not os.path.exists(model_folder_path):
            os.makedirs(model_folder_path)

        file_name = os.path.join(model_folder_path, file_name)
        torch.save(self.state_dict(), file_name)



def train():
    plot_scores = []
    plot_mean_scores = []
    total_score = 0
    record = 0
    agent = Agent()
    game = SnakeGameAI()

    agent.model = Linear_QQNet(11, 256, 3, config=quan_args["linear"]["config"])
    state_dict = torch.load("/Users/thw20/Documents/ichack25/model_4bit/model.pth")
    agent.model.load_state_dict(state_dict)
    # # Iterate through layers and plot 2D weights
    # for layer_name, weights in state_dict.items():
    #     if "weight" in layer_name:
    #         weights_2d = weights.flatten(start_dim=1)  # Flatten to 2D if necessary
    #         if weights_2d.shape[1] == 2:
    #             plot_2d_weights(weights_2d.tolist(), layer_name)
    #         else:
    #             print(f"Layer '{layer_name}' does not have 2D weights.")
    

    while True:
        # get old state
        state_old = agent.get_state(game)

        # get move
        final_move = agent.get_action(state_old)

        # perform move and get new state
        reward, done, score = game.play_step(final_move)
        state_new = agent.get_state(game)

        # train short memory
        agent.train_short_memory(state_old, final_move, reward, state_new, done)

        # remember
        agent.remember(state_old, final_move, reward, state_new, done)

        if done:
            # train long memory, plot result
            game.reset()
            agent.n_games += 1
            agent.train_long_memory()

            if score > record:
                record = score
                print("New record, saving model")
                agent.model.save()

            print('Game', agent.n_games, 'Score', score, 'Record:', record)

            plot_scores.append(score)
            total_score += score
            mean_score = total_score / agent.n_games
            plot_mean_scores.append(mean_score)
            plot(plot_scores, plot_mean_scores)


def eval():
    agent = Agent()
    game = SnakeGameAI()
    # model = Linear_bNet(11, 256, 3, config=quan_args["linear"]["config"])
    model = Linear_QQNet(11, 256, 3, config=quan_args["linear"]["config"])
    # model.load_state_dict(torch.load("/Users/thw20/Documents/ichack25/model_4bit/model.pth"))
    model.load_state_dict(torch.load("/Users/thw20/Documents/ichack25/model_4bit_regulated/model.pth"))


    model_name = 'model_4bit/model.pth'
    state_dict = torch.load("/Users/thw20/Documents/ichack25/"+model_name)
    agent.model.load_state_dict(state_dict)
    # Iterate through layers and plot 2D weights
    for layer_name, weights in state_dict.items():
        if "weight" in layer_name:
            plot_2d_weights(weights, layer_name, model_name)


    model_name = 'model_4bit_regulated/model.pth'
    state_dict = torch.load("/Users/thw20/Documents/ichack25/"+model_name)
    agent.model.load_state_dict(state_dict)
    # Iterate through layers and plot 2D weights
    for layer_name, weights in state_dict.items():
        if "weight" in layer_name:
            plot_2d_weights(weights, layer_name, model_name)

    while True:
        # get old state
        state_old = agent.get_state(game)
        # get move
        # final_move = agent.get_action(state_old)
        final_move = [0,0,0]
        state0 = torch.tensor(state_old, dtype=torch.float)

        prediction = model(state0)

        move = torch.argmax(prediction).item()
        final_move[move] = 1
        
        reward, done, score = game.play_step(final_move)
        # state_new = agent.get_state(game)

        # if done:
        #     game.reset()
        #     print('Score:', score)


def load_integer_weight():
    agent = Agent()
    game = SnakeGameAI()
    agent.model.load_state_dict(torch.load("/Users/thw20/Documents/ichack25/model_8bit/model.pth"))
    # agent.model.load_state_dict(torch.load("/Users/thw20/Documents/ichack25/model_32bit/model.pth"))
    base_quantizer = integer_floor_quantizer_for_hw
    width = 8
    frac_width = 4

    torch.set_printoptions(threshold=float('inf'), profile="full")
    # loop over the params of model and print it 
    for name, param in agent.model.named_parameters():
        param_T = param.T
        value = base_quantizer(param_T, width, frac_width)
        # write it to a txt file no truncation
        with open("/Users/thw20/Documents/ichack25/model_8bit/quantized_weights.txt", "a") as f:
            f.write(f"{name}\n{value}\n")
        # # value = base_quantizer(torch.tensor(value), width, frac_width).item()
        # value = str(bin(value))
        # value_bits = value[value.find("0b") + 2 :]
        # value_bits = "0" * (width - len(value_bits)) + value_bits
        # assert len(value_bits) == width
        # value_bits = hex(int(value_bits, 2))
        # value_bits = value_bits[value_bits.find("0x") + 2 :]
        # value_bits = "0" * (width // 4 - len(value_bits)) + value_bits
        # line_buff = value_bits + line_buff
        


if __name__ == '__main__':
    train()
    # eval()
    # load_integer_weight()

