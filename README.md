# Creation Information
created by: Samantha Parada

date published: December 10th, 2023

# Description

This project contains a program utilizing the Vigenère cipher method to encrypt and decrypt text.

It opens with a menu, giving the user the option to either encrypt text, decrypt text, or exit the program. This menu was created with a do-while loop, so it will reappear once the ciphering has been performed as long as the user chooses not to exit the program. Whether the user chooses to encrypt or decrypt, they will be prompted to enter a message that they want ciphered and the key that goes along with it. If the key is not the same length as the message, it goes through a function that modifies it to be that length. The user is then showed their "modified" key, if it was modified at all. The mapped key and the message are sent off to the encrypt() function if the user had chosen to encrypt their text, or to the decrypt() function if they had chosen to decrypt it. Both functions work in a similar manner: a for loop iterates through each character in the two string arrays and performs calculations to shift the letter of the message by the numerical value of the letter of the key. The equation it uses converts the letters to their numerical values, adds or subtracts them depending on what type of ciphering is being performed, mods them by 26 to restrict the letters to 0-25 where A is 0 and Z is 25, and adds the ASCII value of 'a' (97) when ciphering lowercase letters or 'A' (65) when ciphering uppercase ones. This numerical result is converted into its char value, and pushed into the result string defined within each function. This process repeats until each letter in the message string has been converted, and at the end of each function is a cout statement that displays the converted result.

# Program Instructions

### For the best results possible, please:
- Do not use spaces in the message
> a "pseudo-guard" is in place to prevent false ciphering for a letter that doesn't exist, but this does not mean the whitespace will cipher correctly.
- Only use alphabetical letters
> The Vigenère cipher does not and cannot handle numbers and special symbols.
- Keep the letter case between the message and the key the same
> If the cases do not match, the text will not be ciphered correctly.
>
> e.g. ) if you enter 'HELLO' for your message, your key should also be uppercase; if you enter 'hello,' your key should also be lowercase

Thank you for reading!
