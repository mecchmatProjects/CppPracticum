#include <stdio.h> 
#include <stdbool.h>

#include <ctype.h>

// 4.0.1 b) Chessfield
// 11.1b)

typedef 
struct Field{

  char col; // cols
  unsigned row; // row

}Field;





bool correctness(Field x){
  if(!isalpha(x.col)){
    return false;
  }

  if(x.col<'a' || x.col>'h') return false;
     
  if(x.row==0 || x.row>8) return false;

  return true;
}


int input(Field* x){
  Field res;   
  //unsigned t;
  printf("col, row=");
  scanf(" %c",&res.col);// x->col
  //printf("%i",g);
  //printf("kop=");
  scanf(" %u",&res.row); // x->row
  //res.row = t;
  *x =res;
 return 0;
}

Field input2(){

 Field res;   
  //unsigned t;
  char c;
  printf("col, row");
  scanf(" %c",&с);// x->col
  res.col = toupper(c); 
  //printf("%i",g);
  //printf("kop=");
  scanf(" %u",&(res.row)); // x->row
  
 return res;
}

void output(const Field x){
  printf("%C:%u ",x.col,x.row);
}

// 11.2
bool check(Field x, Field y){

  if(x.col == y.col) return true;
  if(x.row == y.row) return true;
  if(x.col - y.col == x.row - y.row) return true;
  if(x.col - y.col == y.row - x.row) return true;

  return false;
}

int toString(Field x, char* buf, int sizebuf){
   return snprintf(buf,sizeofbuf,"[%c:%u]",x.col,x.row); 
}

int main(){

  Field x,y;
 //x = input2();
  do{
  input(&x); 
  } while(!correctness(x));

  vyvod(x);

  do{
    input(&y); 
  }while(!correctness(y)); 
  vyvod(y);
 
  Field f1 = {'a',1};
  Field f2 = {'a',4};
  Field f3 = {'h',4};
  Field f4 = {'b',2};
  
  printf("\n %d %d %d %d", check(f1,f2),check(f2,f3),check(f1,f4), check(f2,f4)); 


  if(check(x,y)){
    
    printf("\nQueen takes");
    output(x); output(y);
    
    char buf1[10],buf2[10]; 
    toString(x,10,buf1);
    toString(y,10,buf2);
    printf("\nQueen takes %s to %s",buf1,buf2);
  }
  else{
    printf("\nqueen dont take");
  }

}

