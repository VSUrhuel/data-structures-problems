import numpy as np
import matplotlib.pyplot as plt
from matplotlib.patches import Polygon

# Define the parabola equation
f = lambda y: y**2 - 2*y + 1

# Create an array of y values
y = np.linspace(0, 4, 400)

# Calculate x values from the parabola equation
x = f(y)

# Plot the parabola
plt.figure(figsize=(8, 6))
plt.plot(x, y, label='Parabola $y^2 + x - 2y = 1$')

# Fill the area to be revolved
verts = [(0, 0)] + list(zip(x, y)) + [(0, 4)]
area = Polygon(verts, facecolor='lightblue', edgecolor='black', alpha=0.5)
plt.gca().add_patch(area)

# Line y=4
plt.axhspan(ymin=3.5, ymax=3.6, color='red', linestyle='--')
plt.text(1, 3.5, 'dy', color='red', va='top')

plt.axhline(y=4, color='black', linestyle='solid')
plt.text(0, 4, 'y=4', color='black', va='top')

# Labels and title
plt.title('Area bounded by $y^2 + x - 2y = 1$, the y-axis, and y=4')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.legend()
plt.grid(True)

# Show the plot
plt.show()