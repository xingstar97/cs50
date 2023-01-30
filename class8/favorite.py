import csv
from cs50 import SQL

db = SQL("sqlite:///favorite.db")

title = input("Title: ").strip()

rows = db.execute("SELECT count(*) AS counter FROM favorite WHERE title LIKE ?", title)

row = rows[0]

print(row["counter"])

