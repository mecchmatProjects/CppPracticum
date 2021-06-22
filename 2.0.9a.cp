#include <iostream>
#include <math.h>
int main(){
    long long counter = 0;
    long long n; std::cin >> n;
    for(long long i = 0; i < n; ++i){
        bool flag = true;
        long long tmp; std::cin >> tmp;
        tmp = sqrt(tmp);
        if(tmp == 1) continue;
        for(long long d = 2; d * d <= tmp; d++){
            if(tmp % d == 0) flag = false;
        }
        if(flag) counter++;
        std::cout << counter << " ";
    }
}
