from sys import argv
# argv: argument vector, it's a list

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")
# python argv.py, python is not included in the argument, the first argument is the name of the file


try:
    print("My name is", argv[1])
except IndexError:
    print("Too few arguments")



    
for arg in argv:
    print(arg)

for arg in argv[1:]:
    print(arg)

for arg in argv[:-1]:
    print(arg)