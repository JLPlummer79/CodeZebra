"""
Jesse Plummer 2/25/2020 CISC 179
Ceasar encryption program
Takes a line of text and encrypts it by
1st converting it to is ASCII character byte value
2nd shifting it by the distance entered by the user
3rd checking if the shift pushed it past the end of the typeable character
range, and if so wrapping it around to the beginning and applying the shift
"""
plainText = input("Enter a message: ")
distance = int( input("Enter the distance value: ") )
code = " "

for ch in plainText :
    ordValue = ord(ch)
    cipherValue = ordValue + distance
    if ordValue > ord('~'):
        cipherValue = ord('~') - distance - (ord(' ') - ordValue + 1)
    code += chr(cipherValue)
print(code)