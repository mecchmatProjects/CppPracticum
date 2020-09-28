#include <stdio.h> 
#include <stdbool.h>

 bool even_num(int n) {
  return n % 2 == 0; 
 } 
bool f1(int n, int m) { 
 return n % m == 0; } 

int main() { 

int a,b; /// some changes
scanf("%d", &a); scanf("%d", &b); 
bool even_n = even_num(a); 
printf("%d", even_n); 
bool d = f1(a,b); 
printf("%d", d); 

} 
