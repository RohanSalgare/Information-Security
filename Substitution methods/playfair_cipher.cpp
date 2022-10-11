#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//To generate random numbers
int random(int min, int max) // range : [min, max]
{
    static bool first = true;
    if (first)
    {
        srand(time(NULL)); // seeding for the first time only!
        first = false;
    }
    return min + rand() % ((max + 1) - min);
}
//Converts all capital letters to small letters
void toLowerCase(string plain, int ps)
{
    int i;
    for (i = 0; i < ps; i++)
    {
        if (plain[i] > 64 && plain[i] < 91)
            plain[i] += 32;
    }
}
// This function generate the 5x5 matrix using key and all alphabets expect 'j' 
void generateMatrix(char keyM[5][5], string key)
{
    //to count repeatation of letter 
    int map[26] = {0};
    //for matrix's index
    int i = 0, j = 0;
    //Adding key to matrix
    for (int k = 0; k < key.length(); k++)
    {
        //if the character does't exist already in matrix then add it to matrix and update map by 1
        if (map[key[k] - 97] < 1)
        {
            map[key[k] - 97]++;
            keyM[i][j++] = key[k];
        }
        if (j == 5)
        {
            j = 0;
            i++;
        }
    }
    //updating map of 'j' by so condition in loop does't add 'j' in matrix
    map['j' - 97] = 1;
    for (int k = 0; k < 26; k++)
    {
        //checking if there exist any character, if not add to matrix
        if (map[k] == 0)
        {

            keyM[i][j++] = (char)k + 97;
        }
        if (j == 5)
        {
            j = 0;
            i++;
        }
    }
}
// this function return's the encoded character for every continuous two letter of plain text from matrix
string generateCipherChar(char a, char b, char keyM[5][5])
{
    string cipT = "";
    int rowA, colA, rowB, colB;
   // finding the positon of a and b in matrix and store it in rowA,colA and rowB,colB respectively
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (keyM[i][j] == a)
            {
                rowA = i;
                colA = j;
            }

            if (keyM[i][j] == b)
            {
                rowB = i;
                colB = j;
            }
        }
    }

   // if characters are in same column then pick the element next to them and return it
    if (colA == colB)
    {
        cipT += keyM[(rowA + 1) % 5][colA];
        cipT += keyM[(rowB + 1) % 5][colB];
    }
   // if characters are in same row then pick the element next to them
    else if (rowA == rowB)
    {
        cipT.push_back(keyM[rowA][(colA + 1) % 5]);
        cipT.push_back(keyM[rowB][(colB + 1) % 5]);
    }
    //if characters are in differet row and column then pick the element that is in a's row, b's column 
    //for 1st character "a" and b's row, a's column for 2nd character "b"
    else
    {
        cipT.push_back(keyM[rowA][colB]);
        cipT.push_back(keyM[rowB][colA]);
    }

    return cipT;
}
string playfairCipher(string plainText, string key)
{
    string cipherText = "";
    char keyM[5][5];
    generateMatrix(keyM, key);

    int i = 0;
    while (i < plainText.length())
    {
        if (i + 1 < plainText.length() && plainText[i] != plainText[i + 1])
        {
            plainText[i] == 'j' ? plainText[i] = 'i' : plainText[i];
            cipherText += generateCipherChar(plainText[i], plainText[i + 1], keyM);
            i += 2;
        }
        else if (i + 1 < plainText.length() && plainText[i] == plainText[i + 1])
        {
            plainText[i] == 'j' ? plainText[i] = 'i' : plainText[i];

            char temp = 'x';
            while (temp == plainText[i])
            {

                temp = (char)random(97, 122);
            }
            cipherText += generateCipherChar(plainText[i], temp, keyM);
            i++;
        }
        else if (i + 1 == plainText.length())
        {
            plainText[i] == 'j' ? plainText[i] = 'i' : plainText[i];

            // add at last in plaintext one char
            char temp = 'x';
            while (temp == plainText[i])
            {

                temp = (char)random(97, 122);
            }
            cipherText += generateCipherChar(plainText[i], temp, keyM);
            i++;
        }
    }

    return cipherText;
}
int main()
{
    string plainText, key;
    cout << "Enter plain text" << endl;
    getline(cin, plainText);
    cout << "Enter key text" << endl;
    getline(cin, key);

    cout << endl;
    cout << "Plain text: " << plainText << endl
         << "Cipher Text: " << playfairCipher(plainText, key) << endl;
    return 0;
}