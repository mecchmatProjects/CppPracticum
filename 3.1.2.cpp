#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <tuple>

using namespace std;

string count(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            res += 1;
            i++;
        }
    }
    cout << "\nAmount of commas "<<res;
}

string first_comma(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ',') {
            cout<<"\nFirst comma "<<i;
            break;
        }
    }
}
int findLastIndex(string& str, char x)
{
    int index = -1;
    for (int i = 0; i < str.length(); i++)
        if (str[i] == x)
            index = i;
    return index;
}
int main()
{
    string s = "hel,l,o";
    if (s.find(',') != std::string::npos){
        cout<<'+';
        first_comma(s);
        int index = findLastIndex(s, ',');
        cout<<"\nLast comma "<<index;
        count(s);

    }else{
        cout<<'-';
    }
    return 0;
}