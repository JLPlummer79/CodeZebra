"""
Jesse PLummer CISC 179 2/29/2020
shiftRight.py
Takes in a string and moves the last char
to the first position using 2 slices and a
concantanation
"""

outputString = " "
inputString = " "
slicedString1 = " "
slicedString2 = " "


inputString = input("Enter a string of bits: ")
slicedString1 = inputString[-1:]
slicedString2 = inputString[:-1]
outputString = slicedString1 + slicedString2

print(outputString)