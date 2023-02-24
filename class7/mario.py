from cs50 import get_int

'''while do function
infinite loop
'''
while True:
    n = get_int("Height: ")
    if n<0:
        continue 
    else:
        break
    # break the most recently begun while loop

for i in range(n):
    print("#")
