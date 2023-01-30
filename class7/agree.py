from cs50 import get_string

x = get_string("Do you agree? ")
# x = get_string("Do you agree? ").lower()

if x.lower() in ["y","yes"]:
    print("Agreed.")
elif x.lower() in ["n","no"]:
    print("Not agreed.")

