
#include <iostream>

#include <algorithm>

#include "ratio1.h"

namespace Our{

   template <typename T>
   T max( T & a, const T & b){
      if(a>b) return a;
      return b;
   }  

};

int main(){
    using namespace Our;
    int a1=2,b1=3;

    std::cout<<std::max(a1,b1)<<"\n"<<Our::max(a1,b1)<<"\n";

    double a2=3.0,b2=3.12;
    std::cout<<std::max(a2,b2)<<"\n"<<Our::max(a2,b2)<<"\n";

    std::string A("111"); 
    std::string B("222"); 
    std::cout<<std::max(A,B)<<"\n"<<Our::max(A,B)<<"\n";

    Rat r1(1,2);
    Rat r2(2,3);
    //std::cout<<std::max(r1,r2)<<"\n";
    Rat r3 = Our::max(r1,r2);
    r3.output();
}




