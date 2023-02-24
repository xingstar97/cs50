from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

z = x/y

# floor division, return the largest integer
a = x//y

# remainder, return the leftover of the integer division
b = x%y

print(z)
print(a)
print(b)

#float inprecision
print(f"{z:.50f}")