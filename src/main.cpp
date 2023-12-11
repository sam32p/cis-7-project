//programmer: samantha parada
//date:       december 2023

#include <iostream>
#include <string>

using namespace std;

//function declarations
string messageKey(string, string);
void encrypt(string, string);
void decrypt(string, string);

int main()
{
  cout << "*--------------------------------*"
    "\nwelcome to this ciphering program!\n"
    "*--------------------------------*";

  int choice;
  //prints a looping menu as long as user doesn't choose to exit program
  do
  {
    cout << "\n\nwhat would you like to do?\n\n"
      "1. encrypt\n"
      "2. decrypt\n"
      "3. exit program\n\n"
      "please enter 1, 2, or 3: ";
    cin >> choice;

    //error checking for choice made
    while(choice < 1 || choice > 3)
      {
        cout << "\nthe choice you have chosen does not exist!\n"
          "please try again by entering 1 to encrypt, 2 to decrypt, or 3 to exit the program: ";
        cin >> choice;
      }

    //user chooses to encrypt
    if (choice == 1)
    {
      cout << "\n*-------------------------*"
        "\nyou have chosen to encrypt!\n"
        "*-------------------------*\n\n";
      
      //user enters message and key to encrypt
      string message;
      cout << "enter your message, using a non-spaced string of alphabetical letters: ";
      cin.ignore(); //placement here prevents an infinite loop 
      getline(cin, message);

      string key;
      cout << "enter your key, stick to the same case (a-z or A-Z) as used above: ";
      getline(cin, key);
      
      string mappedKey = messageKey(message, key);

      cout << "your mapped key: " << mappedKey;
      
      encrypt(message, mappedKey);
    }
    //user chooses to decrypt
    else if (choice == 2)
    {
      cout << "\n*-------------------------*"
        "\nyou have chosen to decrypt!\n"
        "*-------------------------*\n\n";

        string message;
        cout << "enter your message, using a non-spaced string of alphabetical letters: ";
        cin.ignore();
        getline(cin, message);

        string key;
        cout << "enter your key, stick to the same case (a-z or A-Z) as used above: ";
        getline(cin, key);
      
        string mappedKey = messageKey(message, key);

        cout << "your mapped key: " << mappedKey;

        decrypt(message, mappedKey);
    }
    //if not 1 or 2, the user must have picked 3 to exit the program
    else
    {
      cout << "\n*------------------------------------------*"
        "\nthank you for using this program :D goodbye!\n"
        "*------------------------------------------*";
    }
    
  } while (choice != 3);

  return 0;
}

//function definitions
//generates key same length as message
string messageKey(string m, string k)
{
  if (k.length() < m.length())
    {
      int kLen = k.length();

      for (int i = kLen; i < m.length(); i++)
        {
          k += k[i % kLen];
        }
    }

    return k;
}

//encrypts user message
void encrypt(string enMsg, string enKey)
{
  string enResult = "";

  //traverse text
  for (int i = 0; i < enMsg.length(); i++)
    {
      if(isupper(enMsg[i])) //encrypt uppercase letters
        {
          enResult += char((int(enMsg[i] - 65) + int(enKey[i] - 65)) % 26 + 65);
        }
      else if (enMsg[i] == 32) //whitespace
      {
        enResult += " ";
      }
      else //encrypt lowercase letters
      {
        enResult += char((int(enMsg[i] - 97) + int(enKey[i] - 97)) % 26 + 97);
      }        
    }

  //output the encrypted string
  cout << "\n\nthe encrypted text is: '" << enResult << "'!";
}

//decrypts user message
void decrypt(string deMsg, string deKey)
{
  string deResult = "";

  for (int i = 0; i < deMsg.length(); i++)
    {
      if(isupper(deMsg[i])) //decrypt uppercase letters
        {
          deResult += char((int(deMsg[i] + 65) - int(deKey[i] + 65)) % 26 + 65);
        }
      else if (deMsg[i] == 32) //whitespace
      {
        deResult += " ";
      }
      else //decrypt lowercase letters
      {
        deResult += char((int(deMsg[i] + 97) - int(deKey[i] + 97)) % 26 + 97);
      }        
    }
  
  //output the decrypted string
  cout << "\n\nthe decrypted text is: '" << deResult << "'!";
}
