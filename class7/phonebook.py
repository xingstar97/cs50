from cs50 import get_string

people = {
    "Tom":"123456789",
    "Tim":"234567890"
}

name = get_string("Name: ")
if name in people:
    print(f"number: {people[name]}")