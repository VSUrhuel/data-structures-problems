import numpy as np
import matplotlib.pyplot as plt

# Define the function for y^2
f = lambda x: x * (1 - x)**2

# Create an array of x values
x = np.linspace(0, 1, 400)

# Calculate y values for the positive and negative roots
y_positive = np.sqrt(f(x))

x_dx = 0.5
y_dx = np.sqrt(f(x_dx))

# Plot the curve
plt.figure(figsize=(8, 6))
plt.plot(x, y_positive, label='y = sqrt(x(1-x)^2)')
#plt.plot(x, y_negative, label='y = -sqrt(x(1-x)^2)', color='orange')
plt.fill_between(x, y_positive, color='lightblue', alpha=0.5)

# Add a vertical strip for dx
plt.axvline(x=x_dx, color='green', linestyle='solid')
plt.text(x_dx, 0, 'dx', color='green', ha='right')

# Add a line for the radius
plt.hlines(y_dx, 0, 1, color='red', linestyle='--')
plt.text(0.4, 0.30, 'radius = x', color='red', va='bottom')

# Labels and title
plt.title('Graph of the curve $y^2 = x(1 - x)^2$')
plt.xlabel('x axis')
plt.ylabel('y axis')
plt.legend()
plt.grid(True)

# Show the plot
plt.show()