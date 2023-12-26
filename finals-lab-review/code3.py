import numpy as np
import matplotlib.pyplot as plt
from scipy.integrate import quad

# Define the curve equation
y = lambda x: np.sqrt(x * (1 - x)**2)

# Define the limits of integration
x_lower = 0
x_upper = 1

# Create an array of x values
x_vals = np.linspace(x_lower, x_upper, 100)

# Calculate the corresponding y values from the curve equation
y_vals = y(x_vals)

# Plot the curve
plt.figure(figsize=(8, 6))
plt.plot(x_vals, y_vals, label='Curve: $y^2 = x(1 - x)^2$')

# Fill the area under the curve within the limits
plt.fill_between(x_vals, y_vals, color='blue', alpha=0.3, label='Area to revolve')

# Draw a representative rectangle for the disk method
x_rect = 0.5 # midpoint for demonstration
y_rect = y(x_rect)
plt.gca().add_patch(plt.Rectangle((x_rect, 0), -x_rect, y_rect, color='red', alpha=0.5, label='dx thickness'))

# Annotate the radius and dx
plt.text(x_rect/2, y_rect + 0.1, '$R$', fontsize=12, ha='center')
plt.text(x_rect/2, -0.1, '$dx$', fontsize=12, ha='center')

# Set the labels and title
plt.xlabel('x')
plt.ylabel('y')
plt.title('Volume Generated by Revolving Area about the y-axis')
plt.legend()
plt.grid(True)

# Show the plot
plt.show()