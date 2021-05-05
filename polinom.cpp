#include <iostream>
#include <fstream>

#include "Polinom.h"


Polinom::Polinom(size_t n){
   this->n = n;
   a = new PTYPE[n]; // allocate memory for n coef
}

Polinom::Polinom(size_t n, PTYPE * arr){
   this->n = n;
   a = new PTYPE[n]; // allocate memory for n coef

   for(int i=0;i<n;i++){
       a[i] = arr[i];
   }
}

Polinom::~Polinom(){
   if(n>0)delete[] a; 
}


Polinom::Polinom(const Polinom & p){
   this->n = p.n;
   a = new PTYPE[this->n]; // allocate memory for n coef

   for(int i=0;i<n;i++){
       a[i] = p.a[i];
   }
}

Polinom & Polinom::operator=(const Polinom & p){
  
   delete[] a; 
   this->n = p.n;
   a = new PTYPE[this->n]; // allocate memory for n coef

   for(int i=0;i<this->n;i++){
       a[i] = p.a[i];
   }
}

int Polinom::input(){
   if(n==0){
      std::cout<<"input n=";
      std::cin>>n;
      a = new PTYPE[n];
   }
   for(int i=0;i<n;++i){
      std::cout<<"a["<<i<<"]=";
      std::cin>>a[i];
   } 
}    

void Polinom::output(){
    if(n==0) return;
    if(n==1) {
       std::cout<<(a[0]>=0)?"+":"-";  
       std::cout<<a[0];
       return;
    }  
    std::cout<<a[n-1]<<"*x^"<<(n-1)<<" ";
    for(int i=n-2;i>0;i--){
         std::cout<<((a[i]>=0)?"+":"-");  
         std::cout<<a[i]<<"*x^"<<(i);
    }
    std::cout<<((a[0]>=0)?"+":"-");  
    std::cout<<a[0]<<"\n";
}

 // p.set(k,b) : a[k] =b
int Polinom::set(size_t k, PTYPE b){

    if(k>n-1) return -1;
    a[k] = b;
    return 0;
}

PTYPE Polinom::get(size_t k){

    if(k>n-1) return 0;
    
    return a[k];
}

int saveFile(const char* fname,const Polinom & P){
   std::fstream fp;
   fp.open(fname,std::ios::in);
   if(fp.bad()) {
      std::cerr<<"Error open file "<<fname;
      return -1;
   }
   else{
      fp<<P.n<<": ";
      for(int i=0;i<P.n;++i){
          fp<<P.a[i]<<",";
      }
      fp<<";\n";
      fp.close();
  }

  return 0;
}
int readFile(const char* fname,Polinom & P){
   std::fstream fp;
   fp.open(fname,std::ios::out);
   std::string str;
   if(fp.bad()){
      std::cerr<<"Error open file "<<fname;
      return -1;
   }
   else{
      fp>>P.n; fp>>str;
       
      for(int i=0;i<P.n;++i){
          fp>>P.a[i];   
      }
      fp.close();
  }

  return 0;

}


int main(){

   PTYPE mas[3]= {1,2,3};
   Polinom p0(3,mas);
   p0.output();

   Polinom p1(3);
   p1.input();
   p1.output();

   Polinom p3(p1);   
   Polinom p5(4);
   p5=p3;
   p3.set(1,4.0);
   std::cout<<p3.get(0)<<"\n";
   p3.output();

   saveFile("p1.dat",p3);   
   Polinom p4(4); // ??
   readFile("p1.dat",p4); 
   
   Polinom p[2];
}

