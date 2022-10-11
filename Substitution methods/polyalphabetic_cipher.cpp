#include <iostream>
using namespace std;

string ployalphabeticCipher(string plainText, string key)
{
    string cipherText = "";
    int j = 0;
    for (int i = 0; i < plainText.size(); i++)
    {
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            // Adding the j'th character of key with i'th character of plainText, taking the key in a circular way
            cipherText += ((plainText[i] - 65 + key[(j) % key.length()] - 65) % 26) + 65;
            j++;
        }
        else if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            cipherText += ((plainText[i] - 97 + key[(j) % key.length()] - 97) % 26) + 97;
            j++;
        }
        else
        {
            // if i'th character of plainText is a space or any other symbol then appends to cipherText as it is
            cipherText += plainText[i];
        }
    }
    return cipherText;
}

int main()
{
    string plainText, key;
    cout << "Enter plain text" << endl;
    getline(cin, plainText);
    cout << "Enter key text " << endl;
    getline(cin, key);
    cout << endl;
    cout << "Plain text: " << plainText << endl
         << "Cipher Text: " << ployalphabeticCipher(plainText, key) << endl;
    return 0;
}