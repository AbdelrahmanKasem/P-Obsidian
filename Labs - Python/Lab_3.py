import numpy as np
import matplotlib.pyplot as plt

# =============================================================================
# Exercise 1: Plot a parabola and a hyperbola
# =============================================================================
plt.figure(figsize=(10, 6))

# Parabola
x_parabola = np.linspace(-5, 5, 400)
y_parabola = x_parabola**2
plt.plot(x_parabola, y_parabola, color='blue', linestyle='-', marker='.', label='y = x^2 (Parabola)')

# Hyperbola: must be plotted on two intervals to exclude the pole (x=0)
x_hyp_left = np.linspace(-5, -0.1, 100)
y_hyp_left = 1 / x_hyp_left
x_hyp_right = np.linspace(0.1, 5, 100)
y_hyp_right = 1 / x_hyp_right

plt.plot(x_hyp_left, y_hyp_left, color='red', linestyle='--', marker='x', label='y = 1/x (Hyperbola)')
plt.plot(x_hyp_right, y_hyp_right, color='red', linestyle='--', marker='x')

plt.title('Exercise 1: Parabola and Hyperbola')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.grid(True)
plt.legend()
plt.show()

# =============================================================================
# Exercise 2: Plot several graphs in one coordinate system
# =============================================================================
plt.figure(figsize=(10, 6))
x = np.linspace(-2 * np.pi, 2 * np.pi, 400)

# Plotting functions with labels
plt.plot(x, np.sin(x), color='blue', linestyle='-', marker='', label='y = sin(x)')
plt.plot(x, np.sin(x - 2), color='green', linestyle='--', marker='', label='y = sin(x - 2)')
plt.plot(x, np.sin(x + 1), color='red', linestyle='-.', marker='', label='y = sin(x + 1)')

plt.title('Exercise 2: Multiple Sine Functions')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.grid(True)
plt.legend() # Uses the labels defined in plt.plot()
plt.show()

# =============================================================================
# Exercise 3: Using plt.legend
# =============================================================================
plt.figure(figsize=(10, 6))
x = np.linspace(-2 * np.pi, 2 * np.pi, 400)

plt.plot(x, np.cos(x), color='blue', linestyle='-', label='y = cos(x)')
plt.plot(x, 2 * np.cos(x), color='orange', linestyle='--', label='y = 2cos(x)')
plt.plot(x, 0.3 * np.cos(x), color='green', linestyle='-.', label='y = 0.3cos(x)')
plt.plot(x, -np.cos(x), color='red', linestyle=':', label='y = -cos(x)')

plt.title('Exercise 3: Cosine Functions')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.grid(True)
plt.legend()
plt.show()

# =============================================================================
# Exercise 4: Transformations of graphs of functions
# =============================================================================
# Create a 2x3 grid of subplots
fig, axes = plt.subplots(2, 3, figsize=(15, 8))
x = np.linspace(-5, 5, 400)
f = lambda x: np.abs(x) - 2  # Base function f(x) = |x| - 2

# List of transformations and titles
transforms = [
    (f(x), 'y = f(x)'),
    (f(x - 2), 'y = f(x - 2)'),
    (f(x + 2), 'y = f(x + 2)'),
    (f(2 * x), 'y = f(2x)'),
    (0.5 * f(x), 'y = 0.5f(x)'),
    (-f(x), 'y = -f(x)')
]

# Iterate through the axes and plot each transformation
for ax, (y_vals, title) in zip(axes.flat, transforms):
    ax.plot(x, y_vals, color='purple')
    ax.set_title(title)
    ax.grid(True)
    ax.set_xlabel('x')
    ax.set_ylabel('y')

plt.tight_layout()
plt.show()

# =============================================================================
# Exercise 5: Plotting a function using a logarithmic scale
# =============================================================================
# Set t = -3, -2, ..., 3 and y = 10^t
t = np.arange(-3, 4)
y = 10.0**t

fig, (ax1, ax2) = plt.subplots(2, 1, figsize=(8, 10))

# Linear scale plot
ax1.plot(t, y, 'o-', color='blue')
ax1.set_title('Linear Scale (plt.plot)')
ax1.set_xlabel('t')
ax1.set_ylabel('y')
ax1.grid(True)

# Logarithmic scale plot
ax2.semilogy(t, y, 'o-', color='red')
ax2.set_title('Logarithmic Scale (plt.semilogy)')
ax2.set_xlabel('t')
ax2.set_ylabel('y (log scale)')
ax2.grid(True)

plt.tight_layout()
plt.show()

# =============================================================================
# Exercise 6: Inverse function and symmetry
# =============================================================================
plt.figure(figsize=(8, 8))
x = np.linspace(0, np.pi, 100)
y = np.cos(x)

# For the inverse function on [0, pi], y values go from -1 to 1.
# We plot x_inv = y (values from -1 to 1) and y_inv = x (values from 0 to pi).
x_inv = y
y_inv = x

plt.plot(x, y, 'g:', label='y = cos(x)', linewidth=2)
plt.plot(x_inv, y_inv, 'r-.', label='Inverse function', linewidth=2)
plt.plot([-1.5, 1.5], [-1.5, 1.5], 'b-', label='y = x (Symmetry line)', linewidth=2)

plt.title('Exercise 6: Cosine and its Inverse')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.grid(True)
plt.axis('equal')  # Set equal scale
plt.legend()
plt.show()

# =============================================================================
# Exercise 7: Plotting functions with specific domains
# =============================================================================
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(12, 5))

# a) y = sqrt(x + 3)
x1 = np.linspace(-3, 5, 400) # Domain x >= -3
y1 = np.sqrt(x1 + 3)
ax1.plot(x1, y1, color='blue', linestyle='-', marker='.')
ax1.set_title('y = sqrt(x + 3)')
ax1.set_xlabel('x')
ax1.set_ylabel('y')
ax1.grid(True)

# b) y = sign(x)
# To avoid connecting the discontinuity at x=0, we plot two separate segments
x2_neg = np.linspace(-5, -0.01, 100)
x2_pos = np.linspace(0.01, 5, 100)
ax2.plot(x2_neg, np.sign(x2_neg), color='red', linestyle='-', marker='.')
ax2.plot(x2_pos, np.sign(x2_pos), color='red', linestyle='-', marker='.')
# Mark the discontinuity at x=0 with a specific marker (e.g., white circle with red edge)
ax2.plot(0, 0, 'o', markerfacecolor='white', markeredgecolor='red', markersize=8)
ax2.set_title('y = sign(x)')
ax2.set_xlabel('x')
ax2.set_ylabel('y')
ax2.grid(True)

plt.tight_layout()
plt.show()

# =============================================================================
# Exercise 8: Plotting exponential, logarithmic, and linear functions
# =============================================================================
plt.figure(figsize=(10, 6))

# y = e^x on [-2, 2]
x1 = np.linspace(-2, 2, 100)
y1 = np.exp(x1)
plt.plot(x1, y1, color='blue', linestyle='-', marker='o', markersize=4, label='y = e^x')

# y = ln(x) on [e^-2, e^2]
x2 = np.linspace(np.exp(-2), np.exp(2), 100)
y2 = np.log(x2)
plt.plot(x2, y2, color='green', linestyle='--', marker='s', markersize=4, label='y = ln(x)')

# y = x on [-2, e^2]
x3 = np.linspace(-2, np.exp(2), 100)
y3 = x3
plt.plot(x3, y3, color='red', linestyle='-.', marker='^', markersize=4, label='y = x')

plt.title('Exercise 8: Exponential, Logarithmic, and Linear Functions')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.grid(True)
plt.legend()
plt.show()

# =============================================================================
# Exercise 9: Subplots with Linear and Logarithmic scales
# =============================================================================
# Create 2 plotting areas (subplots)
fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))

# Define x values (0.1 <= x <= 10) to avoid nonpositive values for log scale
x = np.linspace(0.1, 10, 400)

# Functions
y1 = x
y2 = 1 / x
y3 = 1 / np.sqrt(x)

# Plot on the first area (Linear scale)
ax1.plot(x, y1, color='blue', linestyle='-', marker='.', label='y = x')
ax1.plot(x, y2, color='red', linestyle='--', marker='s', label='y = 1/x')
ax1.plot(x, y3, color='green', linestyle='-.', marker='^', label='y = 1/sqrt(x)')
ax1.set_title('Linear Scale')
ax1.set_xlabel('x')
ax1.set_ylabel('y')
ax1.grid(True)
ax1.legend()

# Plot on the second area (Logarithmic scale)
# Using loglog to set both axes to logarithmic scale
ax2.loglog(x, y1, color='blue', linestyle='-', marker='.', label='y = x')
ax2.loglog(x, y2, color='red', linestyle='--', marker='s', label='y = 1/x')
ax2.loglog(x, y3, color='green', linestyle='-.', marker='^', label='y = 1/sqrt(x)')
ax2.set_title('Logarithmic Scale')
ax2.set_xlabel('x (log)')
ax2.set_ylabel('y (log)')
ax2.grid(True, which="both", ls="--")
ax2.legend()

plt.tight_layout()
plt.show()

# =============================================================================
# Exercise 10: Inverse Trigonometric Function and Symmetry
# =============================================================================
plt.figure(figsize=(8, 8))

# Original function: y = sin(x) on [-pi/2, pi/2]
x = np.linspace(-np.pi/2, np.pi/2, 100)
y = np.sin(x)

# Inverse function: y = arcsin(x)
# The domain of arcsin(x) is [-1, 1], and the range is [-pi/2, pi/2]
x_inv = np.linspace(-1, 1, 100)
y_inv = np.arcsin(x_inv)

# Plot the original function (solid cyan line)
plt.plot(x, y, color='cyan', linestyle='-', linewidth=2, label='y = sin(x)')

# Plot the inverse function (red dotted line)
plt.plot(x_inv, y_inv, color='red', linestyle=':', linewidth=2, label='y = arcsin(x)')

# Plot the symmetry line y = x (solid violet line)
plt.plot([-2, 2], [-2, 2], color='violet', linestyle='-', linewidth=2, label='y = x (Symmetry)')

plt.title('Exercise 10: Sine and its Inverse')
plt.xlabel('x-axis')
plt.ylabel('y-axis')
plt.grid(True)
plt.axis('equal') # Equal scale helps visualize the symmetry
plt.legend()
plt.show()
