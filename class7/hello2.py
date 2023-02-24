# define main
def main():
    name = input("What's your name? ")
    hello(name)


# define the default value to to as world
def hello(to = "world"):
    print(f"hello, {to}")

# call main
main()
