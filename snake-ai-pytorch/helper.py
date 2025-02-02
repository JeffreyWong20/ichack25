import matplotlib.pyplot as plt
from IPython import display

plt.ion()

def plot(scores, mean_scores):
    display.clear_output(wait=True)
    display.display(plt.gcf())
    plt.clf()
    plt.title('Training...')
    plt.xlabel('Number of Games')
    plt.ylabel('Score')
    plt.plot(scores)
    plt.plot(mean_scores)
    plt.ylim(ymin=0)
    plt.text(len(scores)-1, scores[-1], str(scores[-1]))
    plt.text(len(mean_scores)-1, mean_scores[-1], str(mean_scores[-1]))
    plt.show(block=False)
    plt.pause(.1)

import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

def plot_2d_weights(weights, layer_name, model_name):

    rows = len(weights)
    cols = len(weights[0])

    x_coords = np.arange(rows)  # Row indices
    y_coords = np.arange(cols)  # Column indices

    # Create meshgrid for 3D plotting
    X, Y = np.meshgrid(x_coords, y_coords)
    Z = np.array(weights)  # Convert to NumPy array for better handling

    # Plotting
    fig = plt.figure(figsize=(8, 6))
    ax = fig.add_subplot(111, projection='3d')
    ax.plot_surface(X, Y, Z.T, cmap='viridis')  # Transpose Z to match dimensions

    # Labels
    ax.set_xlabel("X Axis (Rows)")
    ax.set_ylabel("Y Axis (Cols)")
    ax.set_zlabel("Z Axis (Weights)")
    ax.set_title(model_name+" | 3D Surface Plot of Weights of layer: "+layer_name)

    