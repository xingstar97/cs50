import csv

houses={
    "A": 0,
    "B": 0,
    "C": 0,
    "D": 0,
}

with open("house.csv","r") as file:
    reader = csv.reader(file)
    next(reader)
    for row in reader:
        house = row[1]
        houses[house] += 1

#reader = csv.DictReader(file)
#for row in reader:
#house = row["House"]



for house in houses:
    count = houses[house]
    print(f"{house}: {count}")


