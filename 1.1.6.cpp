#include <iostream>
using namespace std;


int main()
{
    float a, b, c;
    scanf("%f %f %f", &a, &b, &c);
    printf("Your sides are : %f %f %f\n", a, b, c);

    if (a + b > c && a + c > b && b + c > a) {
       printf("Yes, it is triangle\n");
       if (c*c == a*a + b*b){
           printf("Triangle is right");
       }
       if (c*c < a*a + b*b){
           printf("Triangle is acute");
       }
        if (c*c > a*a + b*b){
            printf("Triangle is obtuse");
        }
    } else {
        printf("It is not a triangle");
    }
    return 0;
}