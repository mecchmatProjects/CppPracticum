

#include <iostream>
#include <vector>
#include <cmath>

int vvod(std::vector<double> & v, int d){
 
  double x; 
  for(int i=0;i<d;++i){
    std::cin>>x;
    v.push_back(x);
 }
 return d; 
}

double norma(const std::vector<double> & v){

   double s=0;
   for(int i=0;i<v.size();++i){
      s += v[i]*v[i];
   }
  return sqrt(s);
}

int main(){

  int d,n;

  std::cin>>d;
  std::cin>>n;

  double s =0;
  std::vector<double> v1;
  for(int i=0;i<n;++i){
    vvod(v1,d);
    s += norma(v1);
  }
  std::cout<<"s="<<s;

}
