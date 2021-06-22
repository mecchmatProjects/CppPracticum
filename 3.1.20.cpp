/* Extract all integers from string */
#include <iostream>
#include <sstream>
using namespace std;

void extractIntegerWords(string str)
{
    string integers;
    string other;
    for (int i = 0; i < str.length(); i++)
        if (isdigit(str[i]) == true){
            integers += str[i];
            other += ' ';
        }else{
                other += str[i];
                integers += ' ';
                }
    cout<<"Integers " <<integers;
    cout<<"\nSymbols  "<<other;
}

int main()
{
    string str = "1: 2 3 4 hello.421r 34";
    extractIntegerWords(str);
    return 0;
} 
