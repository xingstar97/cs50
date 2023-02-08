from cs50 import get_int

number = get_int("Number: ")

sum =0
tmp =[0]*16

for i in range (0,16,1):
    if i%2 ==0:
        tmp[15-i] = number//pow(10,15-i)
        if tmp[15-i] >=5:
            tmp1= (2*tmp[15-i])%10+(2*tmp[15-i])//10
            sum += tmp1
        else:
            sum += 2*tmp[15-i]
    else:
        tmp[15-i] = number//pow(10,15-i)
        sum += tmp[15-i]
    # print(f"{15-i}:{tmp[15-i]}")
    # print(sum)
    number = number -tmp[15-i]*pow(10, 15-i)
    # print(number)

if sum%10 ==0:
    if tmp[14] ==3 and tmp[13] in (4,7):
        print("American Express")
    elif tmp[15] ==5 and tmp[14] in range (1,6):
        print("MasterCard")
    elif tmp[15]==4 or tmp[12]==4:
        print("Visa")
else:
    print ("Invalid") 


