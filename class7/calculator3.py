x = input("x: ")
y = input("y: ")

print(x+y)

# Try a = cat
a = int(input("a: "))
b = int(input("b: "))

print(a+b)

try:
    a = int(input("a: "))
except ValueError:
    print("That is not an int!")
    exit()
try:
    b = int(input("b: "))
except ValueError:
    print("That is not an int!")
    exit()

print(a+b)