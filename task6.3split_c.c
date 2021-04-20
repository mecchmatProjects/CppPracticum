
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int split(char* str, char** arr, int n){

char *token;

// Note that the following if-do-while construct is very very
// very very very common to see when using strtok().
int k=0;
// grab the first token (making sure there is a first token!)
if ((token = strtok(str, ".,?! ")) != NULL) {
    do {
        printf("Word: \"%s\"\n", token);
        int len = strlen(token); 
        char *word = malloc(len);
        strcpy(word,token); 
        arr[k++] = word;
        // now, the while continuation condition grabs the
        // next token (by passing NULL as the first param)
        // and continues if the token's not NULL:
    } while ((token = strtok(NULL, ".,?! ")) != NULL);
}

 return k;
}

void freeMas(char** mas, int n){
  for(int i=0;i<n;++i){
     if(mas[i]) free(mas[i]);
  }
}

int main(){

// break up the string into a series of space or
// punctuation-separated words
char str[] = "Where is my bacon, dude?";

char* mas[10];
split(str,mas,5);

 for(int i=0;i<5;++i){
  printf("\n%s",mas[i]);
 }

 freeMas(mas,5);

}
