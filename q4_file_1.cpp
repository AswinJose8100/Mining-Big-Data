#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> removeSpecialCharacter(vector<string> str) 
{ 
    for (int i = 0; i < str.size(); i++) 
    {
        for (int j = 0; j < str[i].length(); j++) 
        {
            if (!isalpha(str[i][j])) 
            {
                str[i].erase(str[i].begin() + j);
                j--;
                
            }
        }
    }

    return str;
}

vector<string> asciiToLower (vector<string> str)
{
    for (int i = 0; i < str.size(); i++) 
    {
        for (int j = 0; j < str[i].length(); j++) 
        {
            if (str[i][j] <= 'Z' && str[i][j] >= 'A') {
                str[i][j] -= ('Z' - 'z');
            }
        }
    }

    return str;
}
  
int main() 
{   string input;
    vector<string> result, result2, result3;
    ifstream file;
    // file.open("/Users/admin/Desktop/MBD");
    file.open("pg100.txt");
    while(file>>input)
    {
      result.push_back(input);
    } 
    file.close();

    result2 = removeSpecialCharacter(result);
    result3 = asciiToLower(result2);

    for (int i = 0; i < result3.size(); i++) {
        cout << "result3: " << result3[i] << endl;
    }
    vector<int> word_len;
    int r=0;
    for(int i=0;i<result3.size();i++){
        word_len.push_back(result3[i].size());

    }
    cout<<" The number of 10 letter words :"<<count(word_len.begin(),word_len.end(),10)<<endl;
    cout<<" The number of 4 letter words :"<<count(word_len.begin(),word_len.end(),4)<<endl;
    cout<<" The length of the longest word = "<< *max_element(word_len.begin(), word_len.end())<<" The frequency: "<<count(word_len.begin(),word_len.end(),33)<<endl; 

    return 0;
}  