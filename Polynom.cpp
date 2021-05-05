
#include <iostream>
#include <cstdio>
#include "Polynom.h"

using namespace std;

Polynom::Polynom(size_t n){
   this->n=n;
   p = new double[n];
}

Polynom::Polynom(size_t n, double * arr){
   this->n=n;
   p = new double[n];
 
   for(int i=0;i<n;++i){
       p[i] = arr[i];
   }  
}

Polynom::~Polynom(){
   if(n) delete[] p;
}

Polynom::Polynom(const Polynom & a){
   this->n=a.n;
   p = new double[a.n];
   for(int i=0;i<n;++i){
       p[i] = a.p[i];
   }

}

Polynom & Polynom::operator=(const Polynom & a){
   if(n>0) delete[] p; 
   this->n=a.n;
   p = new double[a.n];
   for(int i=0;i<n;++i){
       p[i] = a.p[i];
   }

}


int Polynom::set(size_t k, double a){

    if(k>n) return -1;
    p[k] = a;
    return 0;
}

double Polynom::get(size_t k){

    if(k>n) return 0;
    
    return p[k];
}

void Polynom::show(){
   // P = a_0 * x^n-1 + a_1 * x^n-2 +...+a_n-2 * x + a_n-1
   for(int i=0;i<n-1;++i){
      cout<<p[i]<<"*x^"<<(n-i-1)<<"+";
   }

   cout<<p[n-1]<<endl;
}

int saveFile(const char* fname, const Polynom & P){

   FILE* fp = fopen(fname,"w+b");
   if(fp==NULL) {
      cerr<<"Error writing file";
      return -1;
   }

   fwrite(&(P.n),sizeof(size_t),1,fp);
   fwrite(P.p,sizeof(double),P.n,fp);
   fclose(fp);
   return 0;
}

int readFile(const char* fname, Polynom & P){

   FILE* fp = fopen(fname,"rb");
   if(fp==NULL) {
      cerr<<"Error reading file";
      return -1;
   }

   fread(&(P.n),sizeof(size_t),1,fp);
   fread(P.p,sizeof(double),P.n,fp);
   fclose(fp);
   return 0;
}



int main(){
   Polynom p4[10];
   Polynom p3(3);
   double a[5] = {1,2,3};
   Polynom p2(3,a);
  
   Polynom p1(p2); // 
   p3=p2;
   
   p2.show();
   p1.show();
   p3.show();
  
   saveFile("p1.dat",p2);
   readFile("p1.dat",p3);
   p3.show();
   
}


