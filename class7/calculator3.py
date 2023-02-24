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

# when input is cat, it will lead to a name error, as it can not pass int cat to a
try:
    a = int(input("a: "))
except ValueError:
    print("That is not an int!")

print(a)


# if somthing goes wrong do except, if nothing goes wrong, do print a
try:
    a = int(input("a: "))
except ValueError:
    print("That is not an int!")
else:
    print(a)