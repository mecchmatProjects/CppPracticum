#include <stdio.h> 
#include <stdlib.h>
#include <math.h> 
// create zeros matrix nxn
int ** alloc_memory(int n) { 
  int **arr = (int **)malloc(n * sizeof(int *)); 
    for(int i = 0; i < n; i++) 
       arr[i] = (int *)calloc(n, sizeof(int)); 
  return arr; 
} 

//delete matrix 
void free_memory(int **arr, int n) { 
  for(int i = 0; i < n; i++) 
    free(arr[i]);
  free(arr); 
} 

// matrix maltiplication
int ** matr_mult(int **arr, int **arr_2, int n) {
  int **new_arr; 
   new_arr = alloc_memory(n); 
  for (int i = 0; i < n; i++) { 
    for (int j = 0; j < n; j++) { 
         for (int k = 0; k < n; k++) { 
            new_arr[i][j] += arr[i][k] * arr_2[k][j]; 
    } 
  } 
 } 
 return new_arr; 
} 

void print_arr(int **arr, int n) { 
   printf("\n"); 
  for(int i=0; i<n; i++) { 
       for(int j=0; j<n; j++) { 
         printf("%d ", arr[i][j]); } 
   printf("\n"); 
 } 
} 

// input from console row by row
int input_matr(int **arr, int n){

for(int i=0; i<n; i++) { 
     printf("Enter %d values - ", n); 
   for(int j=0; j<n; j++) { 
    scanf("%d", &arr[i][j]); 
   } 
 } 
  return 0;
}

int main() { 
 int n; int **arr, **arr_2, **new_arr; 

 printf("Enter n - "); 
 scanf("%d", &n);
 arr = alloc_memory(n); 
 arr_2 = alloc_memory(n); 
 if(!arr || !arr_2) {
    printf("memory fail"); 
    return -1; // Possible leak here
 }

 printf("First matrix:\n");
 input_matr(arr,n);
 printf("Second matrix:\n");
 input_matr(arr_2,n);

 print_arr(arr, n); 
 print_arr(arr_2, n); 
 new_arr = matr_mult(arr, arr_2, n); 
 print_arr(new_arr, n); 

 free_memory(arr,n); 
 free_memory(arr_2,n); 
 free_memory(new_arr,n); 
 return 0; 
} 
