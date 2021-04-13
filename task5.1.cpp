

#include <iostream>
#include <cmath> //math.h
#include <cfloat>

using namespace std;

double stepin(double x, double y){

   if(x<0){
      if(fabs(y-(int)y)<DBL_EPSILON) return pow(x,y);
      return INFINITY;  
   }
   else if (x<DBL_EPSILON){
      if(y>0) 
       return pow(x,y); 
      return INFINITY;
   }
   return pow(x,y); 
}

int main(){

  double x,y,z;

  cin>>x;
  cin>>y;
  z = pow(x,y);

  cout<<z<<", "<<scientific<<z<<endl;
 
  z = stepin(x,y);
  cout<<fixed<< z<<", "<<scientific<<z<<endl;
}
