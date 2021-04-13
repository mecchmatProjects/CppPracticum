
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>

typedef unsigned long long ULL; 

const size_t MAX_M = 256 * 1024;

int main(){

  ULL mas[MAX_M];
  double res[MAX_M];
  size_t i=0;

  std::ifstream f1;
  std::string answ;
  std::cout<<"From console(c)/or file(name):";
  std::cin>>answ;
  //std::cout.fixed;
  //std::cout.fill(0);  
  //std::cout.precision(5);
   
  if(answ.length()==0 || answ.length()==1 && answ[0]=='c') {
     while(std::cin>>mas[i++]){
     std::clog<<"mas["<<i<<"]="<<mas[i-1];
     }
     
     for(size_t j=i;j!=0;j--){
        res[i-j] = sqrt(mas[j-1]);
        std::cout<<res[i-j]<<"\n";
     }  
 
  }
  else{
     f1.open(answ.c_str());
     while(f1>>mas[i++]){
     std::clog<<"mas["<<i<<"]="<<mas[i-1];
     }
     
     for(size_t j=i;j!=0;j--){
        res[i-j] = sqrt(mas[j-1]);
        std::cout<<std::fixed<<std::setprecision(4)<<res[i-j]<<"\n";
     }  
     f1.close();

  }
  
  

}
