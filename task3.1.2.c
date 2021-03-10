#include <stdio.h>
#include <stdlib.h>
#include <string.h> // strlen()

int firstComma(char *str){
int i=0;
  size_t n = strlen(str); 
  for(i=0;i<n;i++){
     if(str[i]==',') break;
  }

  if(i<n) printf("\nNumber of symbol = %d\n",i);
  else {printf("\nNo comma\n"); i=-1;}

  return i;
}


int main(){

  char str[255]; //

  //scanf("%s",str);
  fgets(str,255, stdin);

  printf("s=%s comma %d\n",str, firstComma(str));
  
}


