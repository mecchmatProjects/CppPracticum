#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool check(char* str){
 int k=0;
 int m = strlen(str);

 for(int i=0;i<m-2;++i){ // without last '\0' and '='

   if (str[i]=='+'||str[i]=='-'){
     if(!(isdigit(str[i+1]) && i<m-3)){
       return false;
      }
   }
   else if(!isdigit(str[i])){
      return false;
   }

 }

  return (str[m-2]=='=');
}

int expr(char* str){

 int sum=0;
 int m = strlen(str); 
 int d=0;
 bool sign = true; 
 for(int i=0;i<m-2;++i){ // without last '\0' and '='
   if(isdigit(str[i])){
     char buf[2]; // use string buf for atoi(char*)
     buf[0] = str[i];
     buf[1] = '\0';
     d = 10*d + atoi(buf); // append digit to number

   }
   else if (str[i]=='+'||str[i]=='-'){
     if(sign) sum += d;
     else sum -= d;
     d=0;
     sign = (str[i]=='+'); // true if +, false if -
   }
   
 }

  if(sign) sum += d;
     else sum -= d;
  return sum; 
}

int expr1(char* str){

 int sum=0;
 int m = strlen(str); 
 int d=0;
 bool sign = true; 
 char buf[20]; // buffer to keep d_i string
 int j=0; 
 for(int i=0;i<m-1;++i){
   if(isdigit(str[i])){ 
    buf[j++] = str[i]; // append digit to number
   }
   else if (str[i]=='+'||str[i]=='-'){
     buf[j]='\0'; //finalize buf
     d = atoi(buf); 
     if(sign) sum += d;
     else sum -= d;
     
     j=0; // nullify buf  
     sign = (str[i]=='+'); // true if +, false if -
   }
   
 }

  buf[j]='\0'; //finalize buf
  d = atoi(buf); 
  if(sign) sum += d;
  else sum -= d;

  return sum; 
}


int main(){

  char s[255];
  fgets(s,255,stdin);

  bool br = check(s);

  if(!br){
    printf("Incorrect Expression");
  }
  else{
   int sum = expr1(s); 
   printf("s=%d",sum);
  }


}
