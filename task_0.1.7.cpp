#include <iostream>


using namespace std;

int main()
{
    long long int x, y;
    scanf("%10lld%10lld", &x,&y);
    printf("Your numbers are : %lld %lld\n", x, y);
    long long int sum = x + y;
    printf("Sum = %lld\n", sum);
    return 0;
}