#include <iostream>
using namespace std;
// Function to generate cipher text
string caecerCipher(string plainText, int key)
{

    string cipherText = "";
    //loop for traversing string
    for (int i = 0; i < plainText.length(); i++)
    {
        // Cheking wheater the current character is capital or small letter
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        { // if current character is capital add the key into ASCII value of current character and append it to cipherText
            cipherText += ((plainText[i] - 64 + key) % 26) + 64;
        }
        else
        {
            // if current character is small letter add the key into ASCII value of current character and append it to cipherText
            cipherText += ((plainText[i] - 96 + key) % 26) + 96;
        }
    }

    return cipherText;
}
int main()
{
    string plainText;
    int key = 1;
    cout << "Enter plain text" << endl;
    getline(cin, plainText);
    cout << "Enter key" << endl;
    cin >> key;
    cout << endl;

    cout << "Plain text: " << plainText << endl
         << "Cipher Text: " << caecerCipher(plainText, key) << endl;
    return 0;
}