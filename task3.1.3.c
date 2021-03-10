#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool check_brackets(char* str){
 int k=0;
 int m = strlen(str); 
 for(int i=0;i<m;++i){
   if(str[i]=='('){
      k++;
   }
   else if (str[i]==')'){
    k--;
   }
   if(k<0) return false;
 }

  return (k==0);
}

void print_excluded_brackets(char* str){

 char buf[255]; 
 int j=0;
 int k=0;
 int m = strlen(str); 
 int state=-1;
 for(int i=0;i<m;++i){
   if(str[i]=='(') {
     k++; 
     if(state==-1) state=i;
   }
   else if (str[i]==')') k--;

   if(state==-1){
     buf[j++] = str[i];
   }  

   if(k==0 && state!=-1) {
      state=-1;
   }
 }

 puts(buf);
}


int main(){

  char s[255];
  fgets(s,255,stdin);

  bool br = check_brackets(s);

  if(!br){
    printf("Incorrect brackets");
  }
  else{
   print_excluded_brackets(s);
  }


}
