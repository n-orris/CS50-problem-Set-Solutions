import sys
import csv
from typing import NamedTuple, List

# exits if incorrect # args provided
if len(sys.argv) != 3:
    print("Usage: python dna.py data.csv sequence.txt")
    sys.exit(1)

# turns the file into a str that can be manipulated
seq_str = ''
seq = open(sys.argv[2])
for char in seq:
    seq_str += char
        

with open(sys.argv[1]) as csvfile:
    reader = csv.reader(csvfile, delimiter = ',')
    # gets all the names of columns
    for first in reader:
        columns = []
        columns = first
        break

columns.remove("name")
strs = []
# first for loop provides the STR to be searched
for pair in columns:
    num = 0
    max = 0
    # loops through the whole sequence searching for a first STR match
    for i in range (0,len(seq_str)):
        # if statement when encountering first match
        if seq_str.count(pair,i,i+len(pair)) == 1:
            num += 1
            # if statement that breaks the count, determines if it is a new high and breaks out of sequence
            if seq_str.count(pair,i+len(pair),i+(2*len(pair))) != 1:
                if max < num:
                    max = num
                num = 0
                continue
    
    # adds the highest length str to a list
    strs.append(max)
    max = 0


with open(sys.argv[1]) as csvfile:
    reader = csv.reader(csvfile, delimiter = ',')
    next(reader)
    for row in reader:
        if len(row) == 4 and int(row[1]) == strs[0] and int(row[2]) == strs[1] and int(row[3]) == strs[2]:
            print(row[0])
            sys.exit(0)
        elif len(row) == 9 and int(row[1]) == strs[0] and int(row[2]) == strs[1] and int(row[3]) == strs[2] and int(row[4]) == strs[3] and int(row[5]) == strs[4] and int(row[6]) == strs[5] and int(row[7]) == strs[6] and int(row[8]) == strs[7]:
            print(row[0])
            sys.exit(0)
    
# if no match is found, exit with no match
print("No Match")
sys.exit(0)
            