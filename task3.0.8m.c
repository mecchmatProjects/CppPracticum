#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//the task is 8)m : я так зрозуміла треба видалити стовпчик k;
int main()
{
  int *a;  
  //int *b;
  int i, j, n, m;

  printf("Введіть кількість рядків: ");
  scanf("%d", &n);
  printf("Введіть кількість стовпчиків: ");
  scanf("%d", &m);

  a = (int*)malloc(n*m * sizeof(int));

  for (i = 0; i<n; i++)  
  {
    for (j = 0; j<m; j++)  
    {
      printf("a[%d][%d] = ", i, j);
      scanf("%d", (a + i*m + j));
    }
  }

  for (i = 0; i<n; i++)  
  {
    for (j = 0; j<m; j++)  
    {
      printf("%5d ", *(a + i*m + j)); 
    }
    printf("\n");
  }
  //free(a);
  //getchar();   getchar();

  int k;
  do {
    printf("Введіть номер стовпчика для видалення:");
    scanf("%d", &k);
  }
  while(k>n);
  k--;
  //for(int i=0;i<n;i++) 
//{
//        a[i][k]=0;

//}   


for (int i=0;i<n; i++) 
{
    for (int j=0;j<m;j++) 
    {
        //if (j==k) j++;
        //cout.width (3);
        *(a + i * (m-1) + j) = *(a + i * m + j);
        //printf("%5d ", *(a + i*m + j));
    }
    for (int j = k+1; j < m; j++){
        *(a + i * (m-1) + j-1) = *(a + i * m + j);
    }

    //printf("\n");
    //cout << "\n";
}
m--;
printf("\nматрица после удаления столбца\n\n");
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%4d", *(a + i * m + j));
      }
      printf("\n");
    }



  return 
