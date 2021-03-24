
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int high;
  char name[20];
} Mountain;

#define N 10

int vvod(Mountain* mt){
  printf("Mountain(name, high):"); 
  scanf("%s",mt->name);
  scanf("%d",&(mt->high));
}

int print(Mountain mnt){
  printf("Mnt(%s, %d):",mnt.name,mnt.high); 
}

void highest(Mountain* mnts, int n){
  int max = mnts[0].high;
  int ind =0;
  for(int i=1;i<n;++i){
       if(max<mnts[i].high){
           max = mnts[i].high;
           ind = i;
       }
  }
  printf("\nName of highest mnt is %s\n", mnts[ind].name);
}

void heighName(Mountain* mnts, int n, char * mname){
  
  for(int i=0;i<n;++i){
       if(strcmp(mname, mnts[i].name)==0){
           printf("\nHeight is %d\n", mnts[i].high);
           return;
       }
  }
  printf("\nNo mountain %s\n", mname);
}

int main(){

  int n;
  printf("N=");
  scanf("%d",&n);
  
  //Mountain* arr = malloc(n*sizeof(Mountain));
   Mountain arr[N];
  for(int i=0;i<n;++i){
    vvod(&arr[i]);
  }

  highest(arr,n);
  
  heighName(arr,n, "K2");
  
  heighName(arr,n, "K3");
  
  //free(arr);
}

