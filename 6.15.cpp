#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str,word;
    getline(cin,str);
    getline(cin,word);

    stringstream ss(str);
    int cnt=0;
    while(ss>>str)
    {
        if(str==word)
            cnt++;
    }
    cout<<cnt<<"\n";
    return 0;
}