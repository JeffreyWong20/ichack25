#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include "logo_patterns.h"
#include "pico/stdlib.h"
#include "pico/rand.h"

#include "render.h"
#include "letters.h"
#include "config.h"
#include "debug.h"
#include "input.h"


#include "bit32_weight.h"
#include "bit8_weight.h"
#include "bit4_weight.h"
#include <algorithm>

uint8_t high_score = 0;
bool LCH = false;

typedef signed int fix;


// Corrected macros for fixed-point conversion and arithmetic
#define int2fix16(a) ((fix)((a) << 16))
#define fix2int16(a) ((int)((a) >> 16))
#define multfix16(a, b) ((fix)(((int64_t)(a) * (int64_t)(b)) >> 16))

#define int2fix4(a) ((fix)((a) << 4))
#define fix2int4(a) ((int)((a) >> 4))
#define multfix4(a, b) ((fix)(((int16_t)(a) * (int16_t)(b)) >> 4))

#define int2fix2(a) ((fix)((a) << 2))
#define fix2int2(a) ((int)((a) >> 2))
#define multfix2(a, b) ((fix)(((int8_t)(a) * (int8_t)(b)) >> 2))


namespace Snake{
    enum class Direction
    {
        UP = 0,
        LEFT = 1,
        DOWN = 2,
        RIGHT = 3
    };

    struct Coord
    {
        uint8_t x = FB_WIDTH / 2;
        uint8_t y = FB_HEIGHT / 2;

        bool operator==(const Coord &) const = default;
    };

    Direction direction = Direction::UP;
    std::deque<Coord> snake;
    Coord fruitCoord;

    void snake_update_bf(uint32_t *fb);

    inline void updatefruitCoordRand()
    {
        do
        {
            int rand_ = get_rand_32();
            uint8_t x = (uint8_t)std::min(rand_ & 0b11111, FB_WIDTH - 1);
            uint8_t y = (uint8_t)std::min((rand_ >> 5) & 0b111, FB_HEIGHT - 1);
            fruitCoord = Coord{x, y};
        } while (std::find(snake.begin(), snake.end(), fruitCoord) != snake.end());
    }

    inline void snake_setup()
    {
        snake.clear();
        direction = Direction::LEFT;
        snake.emplace_back(Coord(FB_WIDTH / 2 + 1, FB_HEIGHT / 2));
        snake.emplace_back(Coord(FB_WIDTH / 2, FB_HEIGHT / 2));
        snake.emplace_back(Coord(FB_WIDTH / 2 - 1, FB_HEIGHT / 2));
        updatefruitCoordRand();
    }

    void handle_game_pad();
    bool check_end(Snake::Coord);

    void loading_screen(uint32_t *fb, uint32_t bit_streams[10])
    {
        const static unsigned char tetris_str[] = "SNAKE";
        for (size_t i = 0; i < 6; i++)
        {
            if(i & 1)
            {
                string_banner_output(fb, tetris_str, ARRAY_LENGTH(tetris_str), FB_WIDTH);
                standard_render_fb(fb, bit_streams);
            }
            else
            {
                clear_fb(fb);
                standard_render_fb(fb, bit_streams);
            }
        }
    }

    void play_snake(uint32_t *fb, uint32_t bit_streams[10])
    {
        clear_fb(fb);
        snake_setup();
        loading_screen(fb, bit_streams);
        print("Setup Done\n");

        clr_ICH();
        Coord head;
        do
        {
            clear_fb(fb);

            if (LCH)
            {
                set_all_ICH();
                LCH = false;
            }
            else
            {
                clr_ICH();
            }

            snake_update_bf(fb);
            handle_game_pad();
            for (size_t i = 1; i < std::max(60 - (snake.size() / 4), 16u); i++)
            {
                render_fb(fb, bit_streams, 10000);
                sleep_ms(4);
            }

            head = snake.front();

            // TODO: Could overflow/underflow cause issues?
            // Coord point_l = Coord{ .x = (uint8_t)head.x-(uint8_t)1, .y = (uint8_t)head.y};
            // Coord point_r = Coord{ .x = (uint8_t)head.x+(uint8_t)1, .y = (uint8_t)head.y};
            // Coord point_u = Coord{ .x = (uint8_t)head.x, .y = (uint8_t)head.y-(uint8_t)1};
            // Coord point_d = Coord{ .x = (uint8_t)head.x, .y = (uint8_t)head.y+(uint8_t)1};

            Coord point_l = Coord{ .x = (uint8_t)head.x+(uint8_t)1, .y = (uint8_t)head.y};
            Coord point_r = Coord{ .x = (uint8_t)head.x-(uint8_t)1, .y = (uint8_t)head.y};
            Coord point_u = Coord{ .x = (uint8_t)head.x, .y = (uint8_t)head.y-(uint8_t)1};
            Coord point_d = Coord{ .x = (uint8_t)head.x, .y = (uint8_t)head.y+(uint8_t)1};


            bool l_collision = check_end(point_l);
            bool r_collision = check_end(point_r);
            bool u_collision = check_end(point_u);
            bool d_collision = check_end(point_d);


            bool dir_l = (direction == Direction::LEFT);
            bool dir_r = (direction == Direction::RIGHT);
            bool dir_u = (direction == Direction::UP);
            bool dir_d = (direction == Direction::DOWN);

            // bool dir_l = (direction == Direction::RIGHT);
            // bool dir_r = (direction == Direction::LEFT);
            // bool dir_u = (direction == Direction::DOWN);
            // bool dir_d = (direction == Direction::UP);

            bool danger_straight = 
              (dir_r && r_collision) || 
              (dir_l && l_collision) || 
              (dir_u && u_collision) || 
              (dir_d && d_collision); 

            bool danger_right = 
              (dir_u && r_collision) || 
              (dir_d && l_collision) || 
              (dir_l && u_collision) || 
              (dir_r && d_collision); 

            bool danger_left = 
              (dir_d && r_collision) || 
              (dir_u && l_collision) || 
              (dir_r && u_collision) || 
              (dir_l && d_collision);

            
            // bool food_left =  fruitCoord.x > head.x;  
            // bool food_right = fruitCoord.x < head.x;  
            // bool food_up =    fruitCoord.y < head.y;  
            // bool food_down =  fruitCoord.y > head.y;  

            bool food_left =  fruitCoord.x > head.x;  
            bool food_right = fruitCoord.x < head.x;  
            bool food_up =    fruitCoord.y < head.y;  
            bool food_down =  fruitCoord.y > head.y;  
            
            int64_t state[11] = {
              danger_straight, danger_right, danger_left, dir_l, dir_r, dir_u, dir_d, food_left, food_right, food_up, food_down
            };

             // Layer 1

            int64_t results [256] = {0};
            for (int c = 0; c < WEIGHT_1_COLS; c++) {
                results[c] = 0;
                for (int r = 0; r < WEIGHT_1_ROWS; r++) {
                    results[c] += multfix16(int2fix16(state[r]), weights_1[r][c]);
                } 
            }

            for (int c = 0; c < WEIGHT_1_COLS; c++) {
                results[c] += bias_1[c];
            }

            // ReLU
            for (int c = 0; c < WEIGHT_1_COLS; c++) {
                results[c] = results[c] > 0 ? results[c] : 0;
            }


            int64_t results2 [WEIGHT_2_COLS] = {0};
            // Layer 2
            for (int c = 0; c < WEIGHT_2_COLS; c++) {
                results2[c] = 0;
                for (int r = 0; r < WEIGHT_2_ROWS; r++) {
                    results2[c] += multfix16(results[r], weights_2[r][c]); 
                } 
            }


            for (int c = 0; c < WEIGHT_2_COLS; c++) {
                results2[c] += bias_2[c];
            }

            uint8_t max_index = 0;
            for (int c = 0; c < WEIGHT_2_COLS; c++) {
                if (results2[c] >= results2[max_index]) {
                    max_index = c;
                }
            }

            
            if (max_index == 1) {
                // TURN RIGHT
                switch (direction) {
                  case Direction::UP:
                    direction = Direction::RIGHT;
                    break;
                  case Direction::RIGHT:
                    direction = Direction::DOWN;
                    break;
                  case Direction::DOWN:
                    direction = Direction::LEFT;
                    break;                  
                  case Direction::LEFT:
                    direction = Direction::UP;
                    break;
                }
            } else if (max_index==2) {
                // TURN Left
                switch (direction) {
                    case Direction::UP:
                        direction = Direction::LEFT;
                        break;
                    case Direction::RIGHT:
                        direction = Direction::UP;
                        break;
                    case Direction::DOWN:
                        direction = Direction::RIGHT;
                        break;
                    case Direction::LEFT:
                        direction = Direction::DOWN;
                        break;
                }
            }

            switch (direction)
            {
            case Direction::UP:
                head.y--;
                break;
            case Direction::LEFT:
                head.x++;
                break;
            case Direction::DOWN:
                head.y++;
                break;
            case Direction::RIGHT:
                head.x--;
                break;
            default:
                break;
            }
            
            snake.emplace_front(head);
            if (head != fruitCoord)
            {
                snake.pop_back();
            }
            else
            {
                LCH = true;
                updatefruitCoordRand();
            }

        } while (!check_end(head));

        uint8_t value = snake.size();
        if (value > high_score)
        {
            high_score = value;
        }

#if DEBUG
        printf("high score: %d, value: %d\n", high_score, value);
#endif
        unsigned char start[] = "SC0R3:000|H1 SC0R3:000";
        for (size_t i = 0; i < 3; i++)
        {
            start[8 - i] = '0' + value % 10;
            value /= 10;

            start[ARRAY_LENGTH(start) - 2 - i] = '0' + (high_score % 10);
            high_score /= 10;
        }

        for (size_t i = 0; i < (string_width(ARRAY_LENGTH(start)) + (FB_WIDTH << 1)); i++)
        {
            string_banner_output(fb, start, ARRAY_LENGTH(start), i);
            standard_render_fb(fb, bit_streams);
            if ((i > 30) && game_pad.updated())
                break;
        }
        clear_fb(fb);
        render_fb(fb, bit_streams);
        game_pad.reset();
    }


    void play_snake_4bit(uint32_t *fb, uint32_t bit_streams[10])
    {
        clear_fb(fb);
        snake_setup();
        loading_screen(fb, bit_streams);
        print("Setup Done\n");

        clr_ICH();
        Coord head;
        do
        {
            clear_fb(fb);

            if (LCH)
            {
                set_all_ICH();
                LCH = false;
            }
            else
            {
                clr_ICH();
            }

            snake_update_bf(fb);
            handle_game_pad();
            for (size_t i = 1; i < std::max(60 - (snake.size() / 4), 16u); i++)
            {
                render_fb(fb, bit_streams, 10000);
                sleep_ms(4);
            }

            head = snake.front();

            Coord point_l = Coord{ .x = (uint8_t)head.x+(uint8_t)1, .y = (uint8_t)head.y};
            Coord point_r = Coord{ .x = (uint8_t)head.x-(uint8_t)1, .y = (uint8_t)head.y};
            Coord point_u = Coord{ .x = (uint8_t)head.x, .y = (uint8_t)head.y-(uint8_t)1};
            Coord point_d = Coord{ .x = (uint8_t)head.x, .y = (uint8_t)head.y+(uint8_t)1};


            bool l_collision = check_end(point_l);
            bool r_collision = check_end(point_r);
            bool u_collision = check_end(point_u);
            bool d_collision = check_end(point_d);


            bool dir_l = (direction == Direction::LEFT);
            bool dir_r = (direction == Direction::RIGHT);
            bool dir_u = (direction == Direction::UP);
            bool dir_d = (direction == Direction::DOWN);


            bool danger_straight = 
              (dir_r && r_collision) || 
              (dir_l && l_collision) || 
              (dir_u && u_collision) || 
              (dir_d && d_collision); 

            bool danger_right = 
              (dir_u && r_collision) || 
              (dir_d && l_collision) || 
              (dir_l && u_collision) || 
              (dir_r && d_collision); 

            bool danger_left = 
              (dir_d && r_collision) || 
              (dir_u && l_collision) || 
              (dir_r && u_collision) || 
              (dir_l && d_collision);


            bool food_left =  fruitCoord.x > head.x;  
            bool food_right = fruitCoord.x < head.x;  
            bool food_up =    fruitCoord.y < head.y;  
            bool food_down =  fruitCoord.y > head.y;  
            
            int8_t state[11] = {
              danger_straight, danger_right, danger_left, dir_l, dir_r, dir_u, dir_d, food_left, food_right, food_up, food_down
            };

             // Layer 1

            int8_t results [256] = {0};
            for (int c = 0; c < WEIGHT_1_COLS; c++) {
                results[c] = 0;
                for (int r = 0; r < WEIGHT_1_ROWS; r++) {
                    results[c] += multfix2(int2fix2(state[r]), weights_1_4bit[r][c]);
                } 
            }

            for (int c = 0; c < WEIGHT_1_COLS; c++) {
                results[c] += bias_1_4bit[c];
            }

            // ReLU
            for (int c = 0; c < WEIGHT_1_COLS; c++) {
                results[c] = results[c] > 0 ? results[c] : 0;
            }


            int8_t results2 [WEIGHT_2_COLS] = {0};
            // Layer 2
            for (int c = 0; c < WEIGHT_2_COLS; c++) {
                results2[c] = 0;
                for (int r = 0; r < WEIGHT_2_ROWS; r++) {
                    results2[c] += multfix2(results[r], weights_2_4bit[r][c]); 
                } 
            }


            for (int c = 0; c < WEIGHT_2_COLS; c++) {
                results2[c] += bias_2_4bit[c];
            }

            uint8_t max_index = 0;
            for (int c = 0; c < WEIGHT_2_COLS; c++) {
                if (results2[c] >= results2[max_index]) {
                    max_index = c;
                }
            }

            
            if (max_index == 1) {
                // TURN RIGHT
                switch (direction) {
                  case Direction::UP:
                    direction = Direction::RIGHT;
                    break;
                  case Direction::RIGHT:
                    direction = Direction::DOWN;
                    break;
                  case Direction::DOWN:
                    direction = Direction::LEFT;
                    break;                  
                  case Direction::LEFT:
                    direction = Direction::UP;
                    break;
                }
            } else if (max_index==2) {
                // TURN Left
                switch (direction) {
                    case Direction::UP:
                        direction = Direction::LEFT;
                        break;
                    case Direction::RIGHT:
                        direction = Direction::UP;
                        break;
                    case Direction::DOWN:
                        direction = Direction::RIGHT;
                        break;
                    case Direction::LEFT:
                        direction = Direction::DOWN;
                        break;
                }
            }

            switch (direction)
            {
            case Direction::UP:
                head.y--;
                break;
            case Direction::LEFT:
                head.x++;
                break;
            case Direction::DOWN:
                head.y++;
                break;
            case Direction::RIGHT:
                head.x--;
                break;
            default:
                break;
            }
            
            snake.emplace_front(head);
            if (head != fruitCoord)
            {
                snake.pop_back();
            }
            else
            {
                LCH = true;
                updatefruitCoordRand();
            }

        } while (!check_end(head));

        uint8_t value = snake.size();
        if (value > high_score)
        {
            high_score = value;
        }

#if DEBUG
        printf("high score: %d, value: %d\n", high_score, value);
#endif
        unsigned char start[] = "SC0R3:000|H1 SC0R3:000";
        for (size_t i = 0; i < 3; i++)
        {
            start[8 - i] = '0' + value % 10;
            value /= 10;

            start[ARRAY_LENGTH(start) - 2 - i] = '0' + (high_score % 10);
            high_score /= 10;
        }

        for (size_t i = 0; i < (string_width(ARRAY_LENGTH(start)) + (FB_WIDTH << 1)); i++)
        {
            string_banner_output(fb, start, ARRAY_LENGTH(start), i);
            standard_render_fb(fb, bit_streams);
            if ((i > 30) && game_pad.updated())
                break;
        }
        clear_fb(fb);
        render_fb(fb, bit_streams);
        game_pad.reset();
    }


    void play_snake_8bit(uint32_t *fb, uint32_t bit_streams[10])
    {
        clear_fb(fb);
        snake_setup();
        loading_screen(fb, bit_streams);
        print("Setup Done\n");

        clr_ICH();
        Coord head;
        do
        {
            clear_fb(fb);

            if (LCH)
            {
                set_all_ICH();
                LCH = false;
            }
            else
            {
                clr_ICH();
            }

            snake_update_bf(fb);
            handle_game_pad();
            for (size_t i = 1; i < std::max(60 - (snake.size() / 4), 16u); i++)
            {
                render_fb(fb, bit_streams, 10000);
                sleep_ms(4);
            }

            head = snake.front();

            Coord point_l = Coord{ .x = (uint8_t)head.x+(uint8_t)1, .y = (uint8_t)head.y};
            Coord point_r = Coord{ .x = (uint8_t)head.x-(uint8_t)1, .y = (uint8_t)head.y};
            Coord point_u = Coord{ .x = (uint8_t)head.x, .y = (uint8_t)head.y-(uint8_t)1};
            Coord point_d = Coord{ .x = (uint8_t)head.x, .y = (uint8_t)head.y+(uint8_t)1};


            bool l_collision = check_end(point_l);
            bool r_collision = check_end(point_r);
            bool u_collision = check_end(point_u);
            bool d_collision = check_end(point_d);


            bool dir_l = (direction == Direction::LEFT);
            bool dir_r = (direction == Direction::RIGHT);
            bool dir_u = (direction == Direction::UP);
            bool dir_d = (direction == Direction::DOWN);


            bool danger_straight = 
              (dir_r && r_collision) || 
              (dir_l && l_collision) || 
              (dir_u && u_collision) || 
              (dir_d && d_collision); 

            bool danger_right = 
              (dir_u && r_collision) || 
              (dir_d && l_collision) || 
              (dir_l && u_collision) || 
              (dir_r && d_collision); 

            bool danger_left = 
              (dir_d && r_collision) || 
              (dir_u && l_collision) || 
              (dir_r && u_collision) || 
              (dir_l && d_collision);


            bool food_left =  fruitCoord.x > head.x;  
            bool food_right = fruitCoord.x < head.x;  
            bool food_up =    fruitCoord.y < head.y;  
            bool food_down =  fruitCoord.y > head.y;  
            
            int8_t state[11] = {
              danger_straight, danger_right, danger_left, dir_l, dir_r, dir_u, dir_d, food_left, food_right, food_up, food_down
            };

             // Layer 1

            int8_t results [256] = {0};
            for (int c = 0; c < WEIGHT_1_COLS; c++) {
                results[c] = 0;
                for (int r = 0; r < WEIGHT_1_ROWS; r++) {
                    results[c] += multfix4(int2fix4(state[r]), weights_1_8bit[r][c]);
                } 
            }

            for (int c = 0; c < WEIGHT_1_COLS; c++) {
                results[c] += bias_1_8bit[c];
            }

            // ReLU
            for (int c = 0; c < WEIGHT_1_COLS; c++) {
                results[c] = results[c] > 0 ? results[c] : 0;
            }


            int8_t results2 [WEIGHT_2_COLS] = {0};
            // Layer 2
            for (int c = 0; c < WEIGHT_2_COLS; c++) {
                results2[c] = 0;
                for (int r = 0; r < WEIGHT_2_ROWS; r++) {
                    results2[c] += multfix4(results[r], weights_2_8bit[r][c]); 
                } 
            }


            for (int c = 0; c < WEIGHT_2_COLS; c++) {
                results2[c] += bias_2_8bit[c];
            }

            uint8_t max_index = 0;
            for (int c = 0; c < WEIGHT_2_COLS; c++) {
                if (results2[c] >= results2[max_index]) {
                    max_index = c;
                }
            }

            
            if (max_index == 1) {
                // TURN RIGHT
                switch (direction) {
                  case Direction::UP:
                    direction = Direction::RIGHT;
                    break;
                  case Direction::RIGHT:
                    direction = Direction::DOWN;
                    break;
                  case Direction::DOWN:
                    direction = Direction::LEFT;
                    break;                  
                  case Direction::LEFT:
                    direction = Direction::UP;
                    break;
                }
            } else if (max_index==2) {
                // TURN Left
                switch (direction) {
                    case Direction::UP:
                        direction = Direction::LEFT;
                        break;
                    case Direction::RIGHT:
                        direction = Direction::UP;
                        break;
                    case Direction::DOWN:
                        direction = Direction::RIGHT;
                        break;
                    case Direction::LEFT:
                        direction = Direction::DOWN;
                        break;
                }
            }

            switch (direction)
            {
            case Direction::UP:
                head.y--;
                break;
            case Direction::LEFT:
                head.x++;
                break;
            case Direction::DOWN:
                head.y++;
                break;
            case Direction::RIGHT:
                head.x--;
                break;
            default:
                break;
            }
            
            snake.emplace_front(head);
            if (head != fruitCoord)
            {
                snake.pop_back();
            }
            else
            {
                LCH = true;
                updatefruitCoordRand();
            }

        } while (!check_end(head));

        uint8_t value = snake.size();
        if (value > high_score)
        {
            high_score = value;
        }

#if DEBUG
        printf("high score: %d, value: %d\n", high_score, value);
#endif
        unsigned char start[] = "SC0R3:000|H1 SC0R3:000";
        for (size_t i = 0; i < 3; i++)
        {
            start[8 - i] = '0' + value % 10;
            value /= 10;

            start[ARRAY_LENGTH(start) - 2 - i] = '0' + (high_score % 10);
            high_score /= 10;
        }

        for (size_t i = 0; i < (string_width(ARRAY_LENGTH(start)) + (FB_WIDTH << 1)); i++)
        {
            string_banner_output(fb, start, ARRAY_LENGTH(start), i);
            standard_render_fb(fb, bit_streams);
            if ((i > 30) && game_pad.updated())
                break;
        }
        clear_fb(fb);
        render_fb(fb, bit_streams);
        game_pad.reset();
    }


    void handle_game_pad()
    {
        if (game_pad.updated())
        {
            if (game_pad.up.pressed)
            {
                direction = Direction::RIGHT;
            }
            if (game_pad.down.pressed)
            {
                direction = Direction::LEFT;
            }
            if (game_pad.left.pressed)
            {
                direction = Direction::UP;
            }
            if (game_pad.right.pressed)
            {
                direction = Direction::DOWN;
            }

            game_pad.reset();
        }
    }

    void snake_update_bf(uint32_t *fb)
    {
        for (const auto &coord : snake)
        {
            fb[coord.y] |= (1 << coord.x);
        }
        fb[fruitCoord.y] |= (1 << fruitCoord.x);
    }

    bool check_end(Snake::Coord front)
    {
        if (std::find(snake.begin() + 1, snake.end(), front) != snake.end())
        {
            return true;
        }
        if (!((front.x < FB_WIDTH) && (front.x >= 0) && (front.y < FB_HEIGHT) && (front.y >= 0)))
        {
            return true;
        }

        return false;
    }
}

#endif