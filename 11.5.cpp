#include <iostream>

template<typename T>

class Array {
private:
    T *arr;
    unsigned long size;

public:
    void PushBack(T value) {
        T *copy = new T[size];
        for (int i = 0; i < size; i++) { copy[i] = arr[i]; }
        arr = new T[size + 1];
        for (int i = 0; i < size; i++) { arr[i] = copy[i]; }
        arr[size] = value;
        size++;
    }

    int shellSort(T value) {
        for (int gap = size / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < size; i += 1) {
                int temp = arr[i];
                int j;
                for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                    arr[j] = arr[j - gap];
                arr[j] = temp;
            }
        }
        return 0;
    }

    int sort(T value) {
        for (int i = 0; i < size; i++) {
            for (int j = i + 1; j < size; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
    }


    void printArray() {
        for (int i = 0; i < size; i++)
            std::cout << arr[i];
    }

};
