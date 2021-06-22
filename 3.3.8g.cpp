#include <stdio.h>
#include <iostream>

using namespace std;

int main() {
    int i, j, k, n, m;
    int **a, **b;
    cout << "N=";
    cin >> n;
    cout << "M=";
    cin >> m;
    k = 2;
    a = new int *[n];
    for (i = 0; i < n; i++)
        a[i] = new int[m];

    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            a[i][j] = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    printf("\n");

    b = new int *[n + k];
    for (i = 0; i < n; i++)
        b[i] = new int[m + k];

    for (i = 0; i < n; i++) {
        for (j = 0; j < m + k; j++)
            if (j < m)
                b[i][j] = a[i][j];
            else
                b[i][j] = 0;
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < m + k; j++)
            printf("%d ", b[i][j]);
        printf("\n");
    }

    for (i = 0; i < n + k; i++)
        delete[] b[i];
    delete[] b;
    for (i = 0; i < n; i++)
        delete[] a[i];
    delete[] a;
}