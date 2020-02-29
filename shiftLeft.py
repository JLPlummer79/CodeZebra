"""
Jesse Plummer CISC 179 2/28/2020
shiftLeft.py Takes in a string, moves 1st char to last position
with two slices and concantanation
"""

outputString = " "
inputString = " "
slicedString1 = " "
slicedString2 = " "
distance = 1


inputString = input("Enter a string of bits: ")
slicedString1 = inputString[0:1]
slicedString2 = inputString[1:]
outputString = slicedString2 + slicedString1

print(outputString)












