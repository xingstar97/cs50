from cs50 import get_int

def main():
    height = get_height()
    for i in range(height):
        print("#")

def get_height():
    while True:
        n = get_int("Height: ")
        if n > 0:
            break
    return n
    # n is declared within loop, but still can be used outsise the loop,
    # it can be used anywhere within the get_height function

main()