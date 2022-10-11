#include "iostream"
#include "bits/stdc++.h"
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
string matrixMultiply(vector<vector<int>>keyMatrix,vector<int>b){
      string encodedChar="";
        int k=0;
        int temp;
     for(int i=0;i<keyMatrix.size();i++){
        temp=0;
        for(int j=0;j<keyMatrix[0].size();j++){
          temp+=(keyMatrix[i][j])*(b[(k++)%b.size()]);
        }
         encodedChar.push_back((temp%26)+97);
     }
     return encodedChar;
}
string hillCipher(string plainText, vector<vector<int>>keyMatrix)
{
    string cipherText = "";
    vector<int>temp;
    for (int i = 0; i <plainText.length(); i+=3)
    {
      temp.push_back(plainText[i]-97);
      temp.push_back(plainText[i+1]-97);
      temp.push_back(plainText[i+2]-97);
      cipherText+=matrixMultiply(keyMatrix,temp);
      temp.clear();    
         
    }
    
    return cipherText;
}

int main()
{
    string plainText;
    int row,col;
    cout << "Enter plain text" << endl;
    getline(cin, plainText);

    cout<<"Enter the number of rows and columns in your key matrix"<<endl;
    cin>>row>>col;
    vector<vector<int>> key(row);
    cout << "Enter key matrix"<<endl;
    int temp;
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
          cin>>temp;
          key[i].push_back(temp);
        }
     }
    toLowerCase(plainText);
    cout << endl;
   cout << "Plain text: " << plainText << endl
         << "Cipher Text: " << hillCipher(plainText, key) << endl;
    return 0;
}