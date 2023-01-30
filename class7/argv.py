from sys import argv

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")
# python argv.py, python is not included in the argument, the first argument is the name of the file

for arg in argv:
    print(arg)

for arg in argv[1:]:
    print(arg)

for arg in argv[:-1]:
    print(arg)