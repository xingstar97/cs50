import csv
from sys import argv, exit


def main():

    # TODO: Check for command-line usage
    if len(argv) != 3:
        print("Enter command-line arguments")
        exit()
    database = argv[1]
    seg = argv[2]
        
    # TODO: Read database file into a variable
    dna =[]
    strs = []
    with open(database, "r") as file:
        reader = csv.DictReader(file)
        strs = reader.fieldnames[1:]
        # FUNCTION reader.filenames 
        # next(reader)
        for row in reader:
            for i in strs:
                row[i] = int(row[i])
            dna.append(row)
        
    # TODO: Read DNA sequence file into a variable
    with open (seg, "r") as file:
        reader = csv.reader(file)
        for row in reader:
            test = row[0]

    # TODO: Find longest match of each STR in DNA sequence
    number = {}
    for i in strs:
        number[i]=longest_match(test, i)

    # TODO: Check database for matching profiles
    # for i in dna:
    #     print(dna[i])
    # THIS IS WRONG

    found = 0
    for i in dna:
        count =0
        for str in number:
            if i[str] == number[str]:
                count +=1
        if count ==len(strs):
            found +=1
            print(i["name"])
            break
    if found ==0:
        print("No match")
    

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
