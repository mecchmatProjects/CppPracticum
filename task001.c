#include <stdio.h>

int main() {
    
    // fix the bug
    double c;
    printf("Enter t in celsius degrees: ");
    scanf("%lf",&c);
    double f = 9.0*c/5.0 + 32.0;
    printf("\nF = %lf\n",f);
}
