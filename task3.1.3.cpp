
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace std;


int main()
{
    int left = 0, right = 0;
    char str[255];
    std::string res;
    fgets(str, 255, stdin);
    for(int i = 0; i < strlen(str); i++){
        if (str[i] == '(') left++;
        if (str[i] == ')') right++;
        if (right > left) {
            cout << "incorrect data";
            return 0;
        }
        if(right == left && str[i] != ')') res += str[i];
    }
    if (left != right){
        cout << "incorrect data";
        return 0;
    }
    cout << res;
    return 0;
}
