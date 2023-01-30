from cs50 import get_string

before = get_string("Before: ")
print("After: ", end = "")

#for a character in the string
for c in before:
    print(c.upper(), end="")
print()

print(before.upper())
