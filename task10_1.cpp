

#include <iostream>
#include <algorithm>

#include "ratio1.h"


using namespace std;


namespace Max{

   template <class T>
   T max(T & a, const T & b){
      cout<< "our max";
      return a>b?a:b;
   } 

}

int main(){

   int a1=2,b1=1;
   double a2=1.5, b2 =3.14;
   string a3("aaaa"), b3("bbb");

   cout<<max(a1,b1)<<", "<<max(a2,b2)<<", "<< max(a3,b3);
   
   cout<<Max::max(a1,b1)<<", "<<Max::max(a2,b2)<<", ";//<<Max::max(a1,b2);

   cout<<Max::max(a3,b3);
   
   Rat r1(1,2);
   Rat r2(3,4);

   Rat r3 = Max::max(r1,r2);
   r3.output();
}




