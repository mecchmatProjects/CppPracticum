
#include "ratio1.h"

#include <fstream>

Rat Rat::add(const Rat & other){
  
   long long int z1  = nominator*other.denominator + other.nominator*denominator;
   long long unsigned z2 = denominator * other.denominator;

   return Rat(z1,z2);
}

Rat Rat::mult(const Rat& other){
 //Rat z; 
  long long int x = nominator * other.nominator; 
  long long unsigned y=denominator * other.denominator;
  return Rat(x,y);

 } 
Rat Rat::subtraction(const Rat &other) { 
 
 long long int z1 =  nominator * other.denominator - other.nominator * denominator; 
 long long unsigned z2 = denominator * other.denominator; 
  
return Rat(z1,z2); 
} 

Rat Rat::division(const Rat &other) { 
 Rat z; 
 z.nominator = nominator * other.denominator;
 z.denominator = denominator * other.nominator;
 z.reduce(); 
 return z; }


long long unsigned gcd(long long unsigned a, long long unsigned b) {
 if (a == 0) return b; if (b == 0) return a; if (a > b) return gcd(b, a % b); 
 else return gcd(a, b % a); 
} 

void Rat::reduce(){
      long long unsigned d = gcd(nominator,denominator);
      nominator /= d;
      denominator /=d; 
   }


bool Rat::less(const Rat& r){
    return (nominator*r.denominator < denominator*r.nominator); 
}


int saveToFile(const char* fname, const Rat & r){
   fstream f;
   f.open(fname,ios::app);
   if (f.bad()){
      cerr<<"bad file"; 
      throw "Bad file"; 
      //return -1;
   }
   try{
     f<<r.nominator<<" "<<r.denominator<<endl;     
   }
   catch(...){
      cerr<<"Error writing to file "<<fname;
      throw 1; 
   }
   f.close();
   return 0;
}

int readFromFile(const char* fname, Rat & r){
   fstream f;
   f.open(fname,ios::in);
   if (f.bad()){
           throw "Bad file"; 
   }
   try{
     f>>r.nominator>>r.denominator;
   }
   catch(...){
      cerr<<"Error reading from file "<<fname;
      throw 12;
   }
   f.close();
   return 0;

}


int main(){

   Rat t1(2,4),t2,t3;
   
   //t1.input();
   t1.output();

   t2.setNom(1);
   try{
      t2.setDenom(0);    
   }
   catch(ZeroDenominator e){
     cout<<e.what(); 
     t2.setDenom(3);
   }
   cout<<endl;    
   t3 = t1.add(t2);
   t3.output();
   try{
    saveToFile("rat1.txt",t3);
   }
   catch(char* s){
      cerr<<"Bad file";
   }
   catch(int x){
      cerr<<"Bad format";  
   } 

   Rat t4; 
   try{
     readFromFile("rat1.txt",t4);
     t4.output();
   }
   catch(char* s){
      cerr<<"Bad file";
   }
   catch(int x){
      cerr<<"Bad format";  
   } 

/*
   Rat mas[10]; 

  for(int i=0;i<5;++i){
     mas[i].input();
     //cin>>mas[i];
  }

  Rat m1 = mas[0]; 

  for(int i=1;i<5;++i){
     if(mas[i].less(m1)){
        m1 = mas[i];
     }
  }

  m1.output();

*/
/*  double eps; 

  cin>>eps;

  Rat s(0,1); // s =0/1;
  Rat r1(2,1),r2(2,2),r3(1,3),r(1,1);
  int i=0;
  while(r1.greaterReal(eps)){
      //r = r1.add(r2);
      //r = r1.add(r3);  
      if(i%2==0){ 
        s = s.add(r);
     }
     else{
       s = s.subtraction(r);
     }
     i++;
     //r1.setDenom(4*i+1);
     //r1.setDenom(4*i+2);
     //r1.setDenom(4*i+3);
     r.setDenom(i*i);
     s.output();cout<<"\n"<<s.value12()<<"\n";
    // r.output();
  }

  s.output();
  cout<<s.value12();
*/
}




