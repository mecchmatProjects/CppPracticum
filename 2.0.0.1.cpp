#include <iostream>

using namespace std;
int main()
{
    const int size(4);
    int mas[size] = {5, 112, 4, 3};
    for(int i = size-1; i>=0; --i){
       cout<<' '<<mas[i];
    }
    return 0;
}