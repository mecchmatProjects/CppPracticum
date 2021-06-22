#include<iostream>


using namespace std;


unsigned *alloc_memory(int n) {
    auto *arr = (unsigned *) malloc(n * sizeof(unsigned *));
    return arr;
}

uint8_t *alloc_memory8_t(int n) {
    uint8_t *arr = (uint8_t *) malloc(n * sizeof(uint8_t *));
    return arr;
}

uint8_t **alloc_memory8_t_in_2d(int n) {
    uint8_t **arr = (uint8_t **) malloc(n * sizeof(uint8_t *));
    for (int i = 0; i <= (n / 2) + 1; ++i) {
        arr[i] = (uint8_t *) calloc(2, sizeof(uint8_t));
    }
    return arr;
}

unsigned *fillArr(unsigned *arr, int n) {
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 16;
    }
    return arr;
}

uint8_t **fillArr8_t_in_2d(uint8_t **newArr, const unsigned *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            newArr[i][0] = arr[i];
        } else {
            newArr[i - 1][1] = arr[i];
        }
    }
    return newArr;
}


uint8_t *fillArr8_t(uint8_t *newArr, const unsigned *arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            newArr[i] = arr[i];
        } else {
            newArr[i - 1] += arr[i];
        }
    }
    return newArr;
}

void printArr(unsigned *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }
}

void printArr8_t_in_2d(uint8_t **arr, int n) {
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            cout << arr[i][0] << " ";
        } else {
            cout << arr[i - 1][1] << endl;
        }
    }
}

void printArr8_t(uint8_t *arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << endl;
    }
}

int main() {
    int n;
    n = 3;
    unsigned *array;
    uint8_t **newArray2d;
    uint8_t *newArray;
    array = alloc_memory(n);
    array = fillArr(array, n);
    newArray2d = alloc_memory8_t_in_2d(n);
    newArray2d = fillArr8_t_in_2d(newArray2d, array, n);
    newArray = alloc_memory8_t(n);
    newArray = fillArr8_t(newArray, array, n);

    cout << "Old array: " << endl;
    printArr(array, n);
    cout << endl << "New uint8_t array in 1d: " << endl;
    printArr8_t(newArray, n);
    free(array);
    free(newArray2d);
    free(newArray);
}