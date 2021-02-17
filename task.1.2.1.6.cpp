#include <iostream> 
using namespace std; 
int fibb_n(int n) { 
 int f_0=0, f_1=1, f_k; 
 if(n <= 1) { return n; } 
 for(int i=1; i<n; i++) { 
  f_k = f_0 + f_1; 
  f_0 = f_1; 
  f_1 = f_k; 
 } 
return f_k; 
} 
int main() { 
int n, next_fib, counter=0, fib_counter=0, sum=0; 
 cout << "Enter sequence - " << endl; 
 next_fib = fibb_n(fib_counter); 
 while(n) { 
  cin >> n; 
  if(counter == next_fib) { 
   cout << "This element is in index " << next_fib <<endl; 
   sum += n; fib_counter += 1; 
   if(fib_counter == 1) { 
       fib_counter += 1; 
   } 
  next_fib = fibb_n(fib_counter); 
 } 
 counter += 1; 
} 
 cout << "Sum - " << sum; 
return 0; 
} 
