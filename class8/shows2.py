import csv
import re

title = input("Title: ").strip().upper()

counter = 0

with open("shows.csv", "r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        if title == row["shows"].strip().upper():
            counter +=1

print(counter)


# with open("shows.csv", "r") as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         title = row["shows"].strip().upper()
#         if "OFFICE" in title:
#         # if re.search("office", title)
#         # search office in tile

#         # if re.search("^(OFFICE|THE OFFICE)$", title)
#         # start with OFFICE or The OFFICE and end with OFFICE
#             counter +=1