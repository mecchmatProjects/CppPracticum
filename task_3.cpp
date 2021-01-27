#include <cstdio>
#include <cmath> // floor

int main(){

    double d1, d2;
    printf("Real number: ");
    scanf("%lf %lf", &d1, &d2);

    double z1 = (d1 + d2)/2;
    int h1 = floor((d1 + d2)/2);
    printf("\nserednye arifmet= %lf, serednye arifmet= %d\n", z1, h1);

    double z2 = 2/(1/d1 + 1/d2);
    int h2 = floor(2/(1/d1 + 1/d2));
    printf("[z2] = %lf, [h2] = %d\n", z2, h2);

}


