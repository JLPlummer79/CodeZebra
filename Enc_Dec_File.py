"""
Jesse Plummer 2/27/2020 CISC 179
Program reads an Encrypted file, decrypts,
and outputs the data into a specified file.
"""

fileName_to_be_Read = input("Enter the input file name: ")
destinationFileName = input("Enter the output file name: ")
distance = int(input("Enter the distance value: "))

f = open(fileName_to_be_Read, 'r')
encryptedText = f.read()
f.close()
plainText = ""

for char in encryptedText:
    ordValue = ord(char)
    cipherValue = ordValue - distance

    if cipherValue < ord(' '):
        cipherValue = ord('~') - (distance - (ord(' ') - ordValue - 1))
    plainText += chr(cipherValue)

print(plainText)

g = open(destinationFileName, 'w')
g.write(plainText)
g.close()


