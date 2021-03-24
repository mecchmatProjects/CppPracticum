
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
   int height;
   char *name;
} Mountain;

int inputMountain(Mountain* mnt){
  printf("Height, Name:\n");
  scanf("%d ",&(mnt->height));
  char buf[20];
  //printf("\n"); 
  //fgets(buf,20,stdin);
  fscanf(stdin,"%s",buf);
  mnt->name = (char*) malloc(strlen(buf));
  //mnt->name[strlen(buf)-3] ='\0';
  strcpy(mnt->name,buf);
}


void deleteMountain(Mountain* mnt){
  free(mnt->name);
}

void deleteMountains(Mountain* mnt, int n){
  for(int i=0;i<n;++i){
    deleteMountain(&(mnt[i]));
  }
}

void printMountain(const Mountain* mnt){
   printf("\n %s, %d", mnt->name,mnt->height);
}

int maxHeight(Mountain* mnts, int n, char* maxname){
  int max = mnts[0].height;
  int ind =0;
  for(int i=1;i<n;++i){
       if(max<mnts[i].height){
           max = mnts[i].height;
           ind = i;
       }
  }
  printf("\nName of highest mnt is %s\n", mnts[ind].name);
  strcpy(maxname,mnts[ind].name);
  return max;
}


int heighName(Mountain* mnts, int n, const char * mname){
  
  for(int i=0;i<n;++i){
       if(strcmp(mname, mnts[i].name)==0){
           printf("\nHeight is %d\n", mnts[i].height);
           return mnts[i].height;
       }
  }
  printf("\nNo mountain %s\n", mname);
  return 0;
}

int main(){

  int n;
  printf("n=");
  scanf("%d",&n);

  Mountain* mas = (Mountain*) malloc(n*sizeof(Mountain));

  for(int i=0;i<n;++i){
      inputMountain(&(mas[i]));
  }

  /*for(int i=0;i<n;++i){
      printMountain(&mas[i]);
  }*/

  char maxName[20];
  maxHeight(mas,n,maxName);
  printf("\nName of highest mountain is %s\n", maxName);
  
  heighName(mas,n, "K2");
  
  heighName(mas,n, "K3");

  deleteMountains(mas,n);

  free(mas);
}
