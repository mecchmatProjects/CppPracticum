#include <iostream>
#include <typeinfo>
#include <cmath>
#include <string>
#include <stdio.h>
#include <cstring>

using namespace std;

string f(int a) {
    long long int n = 0;
    int k,m = 0;
    bool u1,u2,u3=false;
    int b=0;
    while(a) {
        k = a % 2;
        a = a / 2;
        n += k * pow(10, m);
        m++;
    }
    return to_string(n);
}

int main()
{
    int counter = 0;
    int N;
    cout<<"Кількість чисел: ";
    cin>>N;
    int nums[N];
    cout<<"Числа: "<<endl;
    for(int i=0;i<N;i++){
        int x;
        cin>>x;
        nums[i]=x;
        if (f(x).length()>4){
            if(f(x)[4]=='1' and f(x)[5]=='1' and f(x)[7]=='1'){
                counter++;
            }
        }
        
    }
    cout<<" "<<counter;


    return 0;
}