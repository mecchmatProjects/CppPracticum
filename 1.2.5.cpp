#include <iostream>
#include <stdio.h>

int main()
{
    int digit, count;
    long factor;

    printf("Введіть число: ");
    scanf_s("%d", &digit);
    factor = 1;
    for (count = 1;count <= digit;count++)
        factor *= count;
    printf("Факторіал числа %d дорівнює %d", digit, factor);
    return 0;
}
