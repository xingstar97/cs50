from cs50 import get_int

scores=[]
for i in range(3):
    score = get_int("Score: ")
    scores.append(score)
    #scores += [score]

average = sum(scores)/len(scores)
print(f"Average: {average}")

#adding numbers to strings doesn’t make sense. You need to explicitly convert the number to string first, in order to join them together
print("Average: " + str(average))