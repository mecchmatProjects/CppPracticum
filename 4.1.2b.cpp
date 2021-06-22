#include<iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPerfectSquare(long double x)
{
    if (x >= 0) {

        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}
int create(const char* filename, int n, int* array) {
    FILE *file;
    file = fopen(filename, "wb");
    int res = fwrite(array, n, sizeof(int), file);
    fclose(file);
    return res;
}

void read(const char *filename, int n) {
    FILE *file;
    file = fopen(filename, "rb");
    int x = 0;
    int i = 0;
    while (!feof(file)) {
        int read = fread(&x, sizeof(int), 1, file);
        if (read == 0)
            break;
        i++;
        cout << "x[" << i << "] = " << x << endl;
    }
    fclose(file);
}

void create2(const char *filename, int n) {
    FILE *file;
    file = fopen(filename, "rb");
    int x = 0;
    int i = 0;
    int arr[n];
    int amount = 0;

    while (!feof(file)) {
        int read = fread(&x, sizeof(int), 1, file);
        if (read == 0)
            break;

        if (isPerfectSquare(x) == True) {
            arr[i] = x;
            amount++;
        } else {
            arr[i] = -1;
        }
        i++;
    }
    fclose(file);

    int secondArr[amount];
    int j = 0;
    for (i = 0; i < n; ++i) {
        if (arr[i] != -1) {
            secondArr[j++] = arr[i];
        }
    }
    create("G.txt", amount, secondArr);
    read("G.txt", amount);
}

int main() {
    int n;
    cout << "n=";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cout << "arr[" << i << "]=";
        cin >> arr[i];
    }
    create("F.txt", n, arr);
    create2("F.txt", n);
}
