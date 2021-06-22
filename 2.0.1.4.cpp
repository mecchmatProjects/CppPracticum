#include <iostream>
using namespace std;
static const size_t N = 5;
int maximum(int* arr){
    int max = arr[0];

    for (int i = 0; i < N; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
    }
int main()
{
    int i, z, arr[N];

    for (i = 0; i < N; i++)
    {
        scanf("%d", &z);
        arr[i] = z;
    }
    for(i = 0; i< N; i++)
        printf("m[%d] = %d\n", i, arr[i]);
    cout<<maximum(arr);
    return 0;
}