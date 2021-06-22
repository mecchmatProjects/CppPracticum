#include <iostream>
using namespace std;

int f(int num)
{
    int b0, b1, b2, b3;

    b0 = (num & 0x000000FF) >> 0 ;
    b1 = (num & 0x0000FF00) >> 8 ;
    b2 = (num & 0x00FF0000) >> 16 ;
    b3 = (num & 0xFF000000) >> 24 ;

    return((b0 << 16) | (b1 << 24) | (b2 << 0)  | (b3 << 8));
}

int main()
{
    int x = 1;
    if(*(char *)&x == 1) {
        printf("little endian\n");
        printf("%d in middle endian = %d\n", x, f(x));
    } else {
        printf("big endian\n");
        printf("%d in middle endian = %d\n", x, f(x));
    }

    return 0;
}