#include<bits/stdc++.h>
using namespace std;


bool IsDigitsOnly(string s){
    bool b = false;
    if (! s.empty() && std::all_of(s.begin(), s.end(), [](char c){return std::isdigit(c);})) {
        b = true;
    }
    return b;
}

bool checkIsAP(int *arr, int n)
{
    if (n == 1)
        return true;
    sort(arr, arr + n);
    int d = arr[1] - arr[0];
    for (int i=2; i<n; i++)
        if (arr[i] - arr[i-1] != d)
            return false;

    return true;
}

int main()
{
    string str = "2468";
    bool dig = IsDigitsOnly(str);
    int arr[str.length()];
    if (dig==true){
        for(int i=0;i<str.length();i++){
            arr[i] = str[i] - '0';
        }
        int n = sizeof(arr)/sizeof(arr[0]);
        (checkIsAP(arr, n))? (cout << "Yes" << endl) :
        (cout << "No" << endl);

    }


    return 0;
}
