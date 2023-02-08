# TODO
from cs50 import get_string

text = get_string("Text: ").lower()
words = 0
sentences =0
letters = 0

for i in range(0, len(text), 1):
    if text[i] == " ":
        words +=1
    if text[i] in (".", "!", "?"):
        sentences +=1
    if text[i]>='a' and text[i]<='z':
        letters +=1
words +=1
# print(f"letters: {letters}")
# print(f"words: {words}")
# print(f"sentences: {sentences}")

index = round(letters/words *100 * 0.0588 - sentences/words*100*0.296-15.8)

if index <1:
    print("Before Grade 1")
elif index >=16:
    print("Grade 16+")
else:
    print(f"Grade: {index}")
