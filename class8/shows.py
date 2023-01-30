import csv

showlist = {}

with open("shows.csv","r") as file:
    reader = csv.DictReader(file)
    for row in reader:
        show = row["shows"].strip().upper()
        if not show in showlist:
            showlist[show]=0
        showlist[show] +=1

# def get_value(show):
#     return showlist[show]

# for show in sorted(showlist, key = get_value, reverse=True):
for show in sorted(showlist, key = lambda show: showlist[show], reverse=True):
    print(show, showlist[show])



# showlist = set()

# with open("shows.csv","r") as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         show = row["shows"].strip().upper()
#         showlist.add(show)


# showlist = []

# with open("shows.csv","r") as file:
#     reader = csv.DictReader(file)
#     for row in reader:
#         show = row["shows"].strip().upper()
#         if not show in showlist:
#             showlist.append(show)