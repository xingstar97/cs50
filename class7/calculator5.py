'''[]means optional parameters
round(number[, ndigits])'''

x = float(input("x: "))
y = float(input("y: "))

z = round(x+y)

# 2 digits after the decimal
z1 = round(x/y, 2)

print(z)
print(z1)

# print 1,000 instead of 1000
print(f"{z:,}")

