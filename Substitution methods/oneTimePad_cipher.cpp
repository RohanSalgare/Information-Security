#include <iostream>
using namespace std;
void toLowerCase(string &plain)
{
    int i;
    for (i = 0; i < plain.length(); i++)
    {
        if (plain[i] > 64 && plain[i] < 91)
            plain[i] += 32;
    }
}
string oneTimePadCipher(string plainText, string key)
{
    string cipherText = "";
    toLowerCase(key);
    toLowerCase(plainText);
    for (int i = 0; i < plainText.length();i++){
        cipherText += (((plainText[i]-97)+(key[i]-97))%26)+97;
    }
    return cipherText;
}

int main()
{
    string plainText;
    string key;
    cout << "Enter plain text" << endl;
    getline(cin, plainText);
    cout << "Enter key" << endl;
    getline(cin, key);
    cout << endl;
    cout << "Plain text: " << plainText << endl
         << "Cipher Text: " << oneTimePadCipher(plainText, key) << endl;
    return 0;
}