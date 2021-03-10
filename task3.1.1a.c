
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //isdigit() 

void funA(const char* str){
  char buf[255];
  int j=0;
  for(int i=0;i<strlen(str);++i){
      if(isdigit(str[i])){ // i-th symbol is digit
          // do nothing
      }
      else if(str[i]=='+' || str[i]=='-'){ 
         buf[j] = str[i];
         j++;
         buf[j] = str[i];
         j++;
      }
      else{
         buf[j] = str[i];
         j++;
      }
  }

  //printf("%s",buf);
  puts(buf);
}

int funA1(const char* str, char* out){
  
  int j=0;
  for(int i=0;i<strlen(str);++i){
      if(isdigit(str[i])){ // i-th symbol is digit
          // nothing
      }
      else if(str[i]=='+' || str[i]=='-'){ 
         out[j++] = str[i];
         out[j++] = str[i];
      }
      else{
         out[j++] = str[i];
      }
  }
 
  return j;
}

int funA2( char* str){
  char out[255];
  int j=0;
  for(int i=0;i<strlen(str);++i){
      if(isdigit(str[i])){ // i-th symbol is digit
          // nothing
      }
      else if(str[i]=='+' || str[i]=='-'){ 
         out[j++] = str[i];
         out[j++] = str[i];
      }
      else{
         out[j++] = str[i];
      }
  }
  strcpy(str,out);
  
  return j;
}

int main(){

  char str[255]; 

  fgets(str,255,stdin);

  funA(str);
  
  char res[255];
  funA1(str,res);
  puts(res);

  funA2(str);
  puts(str);

}


