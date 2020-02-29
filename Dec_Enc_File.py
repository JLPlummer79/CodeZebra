"""
Jesse Plummer CISC 179 2/28/2020
Dec_Enc_File.py
Program reads a Un-encrypted file, encrypts it, and
sends it to another file.
"""

fileName_to_be_Read = input("Enter the input file name: ")
destinationFileName = input("Enter the output file name: ")
distance = int(input("Enter the distance value: "))
plainText = ""
encryptedText = ""
cipherValue = 0
f = open(fileName_to_be_Read, 'r')

plainText = f.read()
f.close()

for ch in plainText:
    ordValue = ord(ch)
    cipherValue = ordValue + distance
    if ordValue > ord('~'):
        cipherValue = ord('~') - distance - (ord(' ') - ordValue + 1)
    encryptedText += chr(cipherValue)

print(encryptedText)

g = open(destinationFileName, 'w')
g.write(encryptedText)
g.close()