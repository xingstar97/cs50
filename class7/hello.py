answer = input("What's your name? ")

# remove whitespaces from str
answer = answer.strip()

# capitalize the first letter of input
answer1 = answer.capitalize()

# capitalize the first letter of each word
answer2 = answer.title()

# split name into first and last name
first, last = answer.split()
print("hello", first)

print(f"hello, {answer}")

# "," automatically gives a space, whereas "+" does not
print("hello,", answer)

# \ (escape character) print litera ""
print("hello, \"friends\"")