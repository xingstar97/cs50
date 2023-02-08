from cs50 import get_int

height = get_int("Height: ")
if not height in range(1,8):
    print("Enter the height!")
for i in range (height):
    print(" "*(height-i-1), end = "")
    print("#"*(i+1), end = "")
    print(" "*2, end = "")
    print("#"*(i+1))
