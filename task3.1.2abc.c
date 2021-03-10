/*
2) Дано рядок, серед символів якого є принаймні одна кома, а може й немає
її. Знайти номер
а) першої по порядку коми;
б) останньої по порядку коми;
в) кількості ком

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen()

#define N 255

int firstComma(char *str){

  int i=0;
  while(str[i]!='\0'){
     if(str[i]==',') break;
     i++;
  }

  if(i>=strlen(str))  {
     printf("\nNo comma\n"); 
     i=-1;
  }

  return i;
}

int lastComma(char* str){

  int n = strlen(str)-1;

  while(n>=0){
     if(str[n]==',') break;
     n--;
  } 

  return n;
} 

int numberOfCommas(char* str){

  int i = 0;
  int k = 0; 
  //while(str[i]!='\0'){ 
  for(i=0;i<strlen(str);++i){
     if(str[i]==',') {k++;}
     i++;
  }
  return k;
}


int main(){

   char str[N]; // char* - string type in C
               // char* s = NULL pointer  - malloc(N);
   printf("Input string:");
   
   //scanf("%s",str);
   fgets(str,N,stdin);

   int m = lastComma(str);
   if(m==-1) {
      printf("\nString %s has no comma",str); 
   }
   else{
    printf("\nS=%s  its last comma on position %d",str,m); 
   }

   m = firstComma(str);
   printf("\nFirst comma on position %d, number of them=%d",m, numberOfCommas(str)); 

}

