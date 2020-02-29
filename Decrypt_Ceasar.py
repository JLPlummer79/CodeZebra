"""
Jesse Plummer 2/26/2020 CISC 179
Decrypt a Ceasar encryption
Program takes in a line of text (encrypted)
and a distance value that will decrypt the message
Difficulty was getting the beginning space right, it is space, not !
"""

encryptedText = input("Enter an encrypted message: ")
distance = int(input("Enter the distance value: "))
plainText = " "

for ch in encryptedText :
    ordValue = ord(ch)
    cipherValue = ordValue - distance

    if cipherValue < ord(' ') :
        cipherValue = ord('~') - (distance - (ord(' ') - ordValue -1))
    plainText += chr(cipherValue)

print(plainText)
