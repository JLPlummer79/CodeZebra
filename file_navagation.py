"""
Jesse Plummer CISC 179 3/3/2020
file_navagation.py
reads a file line by line into a list.
Then it executes a loop that asks for an integer
that corresponds to the line.  Entering 0 exits the
program.
"""
file = input("Enter the input file name: ")
f = open(file, "r")
lines = f.readlines()
f.close()
entry = 1
choice = 1
num_of_lines = len(lines)
while choice != 0:
    print("The file has ", num_of_lines, "lines.")
    entry = input("Enter a line number [0 to quit]: ")
    choice = int(entry)
    if choice != 0 and choice < len(lines)-1:
        print(choice,":   ", lines[int(choice-1)])


