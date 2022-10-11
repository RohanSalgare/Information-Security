#include <iostream>
using namespace std;

string ployalphabeticCipher(string plainText)
{
    string cipherText = "";
    // Characters to place at i'th Character in plainText
    char codedSmallLettr[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O',
                              'P', 'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K',
                              'L', 'Z', 'X', 'C', 'V', 'B', 'N', 'M'};
    for (int i = 0; i < plainText.size(); i++)
    {
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            // Picks the Character from the codedSmallLettr with respect to the serial number of alphabetic characters and appends to cipherText
            cipherText += codedSmallLettr[(plainText[i] + 32) - 97];
        }
        else if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            // Picks the Character from the codedSmallLettr with respect to the serial number of alphabetic characters and appends to cipherText
            cipherText += codedSmallLettr[(plainText[i]) - 97];
        }
        else
        {
            // if i'th character is a space or any other symbol then appends to cipherText as it is
            cipherText += plainText[i];
        }
    }
    return cipherText;
}

int main()
{
    string plainText;
    cout << "Enter plain text" << endl;
    getline(cin, plainText);
    cout << endl;

    cout << "Plain text: " << plainText << endl
         << "Cipher Text: " << ployalphabeticCipher(plainText) << endl;
    return 0;
}