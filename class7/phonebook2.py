import csv
from cs50 import get_string

file = open("phonebook.csv","a")
#append mode: continue to write

name = get_string("Name: ")
number = get_string("Number: ")

writer = csv.writer(file)
writer.writerow([name, number])

file.close()

