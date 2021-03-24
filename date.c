#include <stdio.h>

// 4.0.1 a) date
// 11.1a)
typedef struct {
  int day; 
  int month; 
  int year; 
} Date;



int checkDate(const Date* x){
 int mas[12] ={31,28,31,30,31,30,31,31,30,31,30,31}; 

 if(x->year<1900 || x->year>2200) return -1;
 if(x->month<1 || x->month>12) return -2;
 if(x->day<0 || x->day>mas[x->month-1]) return -3;

 return 0;
}


 // input Date
int input(Date* x){
 
 scanf(" %d",&x->day); //x->day == (*x).day
 scanf(" %d",&x->month);
 scanf(" %d",&x->year);
 
 return 0;
}


void vyvod(const Date x){
  printf("\nDate= %2d.%2d.%4d",x.day,x.month,x.year);
}

// leap year if %4 and not %200
int leapYear(int year){
  return (year%4==0) && (year%200!=0);
}


Date yesterday(const Date x){
  
   int dayMonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

   Date res = x; 
   if(x.day>1){
      res.day--;
      return res;   
    }
     
  if (x.month>1){
      res.month--;
      res.day = dayMonth[res.month-1];
      if(leapYear(x.year) && res.month==2) res.day=29;
      return res;
  }  

  if (x.month==1){
      res.year--; 
      res.month=12;
      res.day = 31;
     return res;
  }  
  fprintf(stderr,"Yakas fignya");
  return res; 
}


int main(){

   Date dat1;
   int r=-1;
   do{
     printf("Input date:");
    input(&dat1);
    if(checkDate(&dat1)==0) break;
  }while(1);
   
   vyvod(dat1);
   vyvod(yesterday(dat1));

   printf("\n");
   Date d1 = {23,2,2020};
   Date d2 = {1,1,2021};
   Date d3 = {1,5,2020};
   Date d4 ={1,3,2020};
   Date d5 ={1,3,2019};
   
 vyvod(yesterday(d1));
 vyvod(yesterday(d2));
 vyvod(yesterday(d3));
 vyvod(yesterday(d4));
 vyvod(yesterday(d5));
  
}


/*


int main(){

  Date x,y,z;
  input(&x);
  vyvod(x);
  y = yesterday(x);
 vyvod(y); 
 // input(&y);
}
*/
