
#include <iostream>
#include <vector>
#include <cmath>

int vvod(std::vector<double> & s, int d){
  double x; 
  std::cout<<"input vector:";
  for(int i=0;i<d;i++){
    std::cin>>x;
    s.push_back(x);
  }
  return d;
}


double norm(const std::vector<double> & s){
  
   double r =0;
   for(int i=0;i<s.size();i++){
      r += s[i]*s[i];
   }
   return sqrt(r);
}

int main(){

 int n,d;
 std::cout<<"n,d";
 std::cin>>n>>d;

std::vector<double> v;
 double s=0;
for(int i=0;i<n;i++){
  vvod(v,d);
  s += norm(v);
}

std::cout<<"s="<<s;
}
