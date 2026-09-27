import math


# ============================================================
# EXERCISE 1
# ============================================================
# Function:
#   y = sqrt(x - 1), if x >= 1
#   y = x^3,        if x < 1
#
# Input example:
#   5
#
# Output example:
#   y = 2.000
#
# Explanation:
# We define the function calc_y(x).
# If x >= 1, we calculate sqrt(x - 1).
# Otherwise, we calculate x^3.
# The result is printed with 3 digits after the decimal point.

def calc_y(x):
    if x >= 1:
        return math.sqrt(x - 1)
    else:
        return x ** 3


print("\n========== EXERCISE 1 ==========")

x = float(input("Enter x: "))
y = calc_y(x)

print(f"y = {y:.3f}")


# ============================================================
# EXERCISE 2 - VARIANT 1
# ============================================================
# Function:
#   f(x) = x - 1,       if x <= -pi
#   f(x) = 2*cos(x),    if -pi < x <= pi
#   f(x) = 2,           if x > pi
#
# Input example:
#   0
#
# Output example:
#   f(x) = 2.00
#
# Explanation:
# We use if / elif / else to determine which formula
# should be used for the entered value of x.
#
# NOTE:
# This is VARIANT 1.
# Replace this function if your assigned variant is different.

def f(x):
    if x <= -math.pi:
        return x - 1
    elif x <= math.pi:
        return 2 * math.cos(x)
    else:
        return 2


print("\n========== EXERCISE 2 ==========")

x = float(input("Enter x: "))
y = f(x)

print(f"f(x) = {y:.2f}")


# ============================================================
# EXERCISE 3
# ============================================================
# Calculate:
#
#       y = a*x^2 + c
#
# for x from -5 to 5 with a step of 0.5.
#
# Input example:
#   a = 2
#   c = 3
#
# Output example:
#   -5.0    53.00
#   -4.5    43.50
#   ...
#   5.0     53.00
#
# Explanation:
# i goes from -10 to 10.
# Dividing i by 2 gives:
#
# -10/2 = -5
# -9/2  = -4.5
# ...
# 10/2  = 5
#
# This gives 21 values of x.

print("\n========== EXERCISE 3 ==========")

a = int(input("Enter a: "))
c = int(input("Enter c: "))

print("x\tax^2 + c")
print("-" * 20)

for i in range(-10, 11):
    x = i / 2
    y = a * x ** 2 + c

    print(f"{x:.1f}\t{y:.2f}")


# ============================================================
# EXERCISE 4
# ============================================================
# Find the maximum value of:
#
#       f(x) = x * sin(x)
#
# for:
#
#       x = 0, 0.1, 0.2, ..., 2
#
# There are 21 points.
#
# Input:
#   No input is required.
#
# Output example:
#   x = 2.0
#   f(x) = 1.818595
#
# Explanation:
# We calculate f(x) for every point.
# If the new value is bigger than the current maximum,
# we save the new value and its x.

print("\n========== EXERCISE 4 ==========")

max_y = float("-inf")
max_x = 0

for i in range(21):
    x = i / 10
    y = x * math.sin(x)

    if y > max_y:
        max_y = y
        max_x = x

print(f"x = {max_x:.1f}")
print(f"f(x) = {max_y:.6f}")


# ============================================================
# EXERCISE 5
# ============================================================
# Enter a positive integer n where:
#
#       1 <= n <= 30
#
# Then print a staircase.
#
# Input example:
#   5
#
# Output:
#   1
#   12
#   123
#   1234
#   12345
#
# Explanation:
# The outer loop controls the number of rows.
# The inner loop prints numbers from 1 to the row number.
#
# We use a while loop to make sure that n is between 1 and 30.

print("\n========== EXERCISE 5 ==========")

while True:
    n = int(input("Enter n (1-30): "))

    if 1 <= n <= 30:
        break

    print("Invalid input. Enter a number from 1 to 30.")


for i in range(1, n + 1):

    for j in range(1, i + 1):
        print(j, end="")

    print()


# ============================================================
# EXERCISE 6
# ============================================================
# Enter two positive integers A and B where:
#
#       0 < A < B
#
# Print every integer from A to B.
# Each number must be printed as many times as its value.
#
# Input example:
#   A = 2
#   B = 5
#
# Output:
#   2 2
#   3 3 3
#   4 4 4 4
#   5 5 5 5 5
#
# Explanation:
# The outer loop goes from A to B.
# For every number i, the inner loop runs i times.
# Therefore, number 4 is printed 4 times, etc.

print("\n========== EXERCISE 6 ==========")

while True:
    A = int(input("Enter A: "))
    B = int(input("Enter B: "))

    if 0 < A < B:
        break

    print("Invalid input. We need 0 < A < B.")


for i in range(A, B + 1):

    for j in range(i):
        print(i, end=" ")

    print()