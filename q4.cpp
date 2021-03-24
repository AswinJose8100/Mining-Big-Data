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
int mostFrequent(vector<int> arr) 
{ 
    // Sort the array 
    sort(arr.begin(),arr.end()); 
  
    // find the max frequency using linear traversal 
    int max_count = 1, res = arr[0], curr_count = 1; 
    for (int i = 1; i < arr.size(); i++) { 
        if (arr[i] == arr[i - 1]) 
            curr_count++; 
        else { 
            if (curr_count > max_count) { 
                max_count = curr_count; 
                res = arr[i - 1]; 
            } 
            curr_count = 1; 
        } 
    } 
  
    // If last element is most frequent 
    if (curr_count > max_count) 
    { 
        max_count = curr_count; 
        res = arr[arr.size() - 1]; 
    } 
  
    return res; 
} 
  
int main() 
{   string input;
    vector<string> result, result2, result3;
    ifstream file;
    // file.open("/Users/admin/Desktop/MBD");
    file.open("3399.txt");
    while(file>>input)
    {
      result.push_back(input);
    } 
    file.close();

    result2 = removeSpecialCharacter(result);
    result3 = asciiToLower(result2);

    /*for (int i = 0; i < result3.size(); i++) {
        cout << "result3: " << result3[i] << endl;
    }*/
    vector<int> word_len;
    int r=0;
    for(int i=0;i<result3.size();i++){
        word_len.push_back(result3[i].size());

    }
    cout<<" The number of 2 letter words :"<<count(word_len.begin(),word_len.end(),2)<<endl;
    cout<<" The number of 5 letter words :"<<count(word_len.begin(),word_len.end(),5)<<endl;
    cout<<" Most frequent word length :"<<mostFrequent(word_len)<<" Frequency :"<<count(word_len.begin(),word_len.end(),3)<<endl;
    
   

 

    return 0;
}  