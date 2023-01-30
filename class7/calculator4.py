from cs50 import get_int

x = get_int("x: ")
y = get_int("y: ")

z = x/y
a = x//y

print(z)
print(a)

#float inprecision
print(f"{z:.50f}")
