#include <iostream> 

static const int N =10;

void enter_elementwise(double matr[N][N], int n, int m) {
  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) { 
      std::cout << "a[" << i << "][" << j << "]="; 
      std::cin >> matr[i][j];
    }
  }
} 

void enter_row(double matr[N][N], int n, int m) { 
  for(int i=0; i<n; i++) { 
     std::cout << "Enter " << m << " elements - "; 
      for(int j=0; j<m; j++) { 
         std::cin >> matr[i][j];
       } 
  } 
} 

void print(double matr[N][N], int n, int m) {
  for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) { 
       std::cout << matr[i][j] << " "; 
      } 
      std::cout << std::endl; 
  }
} 

int main() { 

  int n, m; 
  std::cout << "Enter n and m - "; 
  std::cin >> n >> m; 

 double matrix[N][N]; 

 enter_elementwise(matrix, n, m);
 print(matrix, n, m);

 enter_row(matrix, n, m);
 print(matrix, n, m);

 return 0; 
} 
