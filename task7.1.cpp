
/*
 class rational number

*/

#include <iostream>

#include <exception> // to use std::exception
#include <fstream>

class ZeroDenom : public std::exception{

   public: 
   const char* what(){
     return "Denominator can\'t be 0";
   } 
     
};


class Ratio{
   //public:
   private:
     int nominator;
     unsigned denominator;

  public: 

   Ratio(){ 
         nominator=1; 
         this->denominator =1; 
   }

   Ratio(int x, unsigned y): nominator(x),denominator(y){ 
     if(!denominator) throw ZeroDenom();
   } 

   void show(){
      std::cout<<nominator<<"/"<<denominator<<std::endl;
   }

   int input(){
      std::cout<<"n/m=";
      std::cin>>nominator>>denominator;
      if(!denominator) throw ZeroDenom(); 
   }

   void setNom(int nominator){
         this->nominator = nominator; 
   }

   int setDenom(unsigned y){
       if(y==0) { // throw exception
           std::cerr<<"zero denominator!";
           throw ZeroDenom();
       }
       denominator = y;
       return 0;
   }
     
   // multiplication
   Ratio mult(const Ratio& other);
   //addition

   Ratio add(const Ratio& other);

   unsigned gcd(unsigned x, unsigned y);//Greatest Common Divisor

   void reduce();

   friend std::ostream & operator<<(std::ostream& f, const Ratio& r){
      f<<r.nominator<<"/"<<r.denominator<<std::endl;
      return f;
   }

   friend std::istream & operator>>(std::istream& f, Ratio& r){
      f>>r.nominator>>r.denominator;
      return f;
   }

  Ratio operator+(const Ratio& other);  

  bool operator< (const Ratio& a){
     return nominator*a.denominator < denominator * a.nominator;
  }

   bool operator< (double eps){
     return double(nominator)/denominator <eps;
  }

  friend void writeToFile(std::string fname,const Ratio& r); // дружня функція
};


void writeToFile(std::string fname, const Ratio& r){
   
   try{
    std::fstream f1;
    f1.open(fname.c_str(), std::ios::app);
    
    f1 << r.nominator<<r.denominator;
     f1.close();
   }
   catch(...){
    std::cerr<<"problems with writing to file";
  }
}

Ratio Ratio::add(const Ratio& other){
    //Ratio res;
    int nominator1 = nominator * other.denominator + denominator *other.nominator;
    unsigned denominator1 = denominator * other.denominator;
    return Ratio(nominator1,denominator1);
}


Ratio Ratio::operator+(const Ratio& other){
    //Ratio res;
    int nominator1 = nominator * other.denominator + denominator *other.nominator;
    unsigned denominator1 = denominator * other.denominator;
    return Ratio(nominator1,denominator1);
}

unsigned Ratio::gcd(unsigned a, unsigned b) { 
  if (b == 0) return a; return gcd(b, a % b); }


void Ratio::reduce(){
   unsigned d = gcd(nominator, denominator);
   nominator /= d;
   denominator /=d;
}


Ratio Ratio::mult(const Ratio& other) { 
      Ratio res;
      res.nominator = nominator * other.nominator; 
      res.denominator = denominator * other.denominator; 
      return res; 
}

int main(){

  Ratio p1;
  Ratio p2(1,2);
  //Ratio p4,p3 = p1.add(p2);
  Ratio p4,p3 = p1 + p2;
  //p3.show();
  std::cout<<p3;
  p4 = p1.mult(p2);
  p4.show();
  
  std::cout<<std::boolalpha<<(p4<p3);

  p1.setNom(1);

  writeToFile("rat1.dat",p3);
  
  try{
    std::cout<<"input y";
    unsigned y;
    std::cin>>y;  
    p1.setDenom(y);

  }
  catch(ZeroDenom& e){
    std::clog<<"Exception caught";
  }
  


  /*
  Ratio r1,r2,r3;
  try{
  r1.input();
  r1.show(); 
  }
  catch(...){
    std::cout<<"error";
 } 
  r2.input();
  r2.show();
  
  r3 = r1.add(r2); // r1+r2
  r3.reduce();
  r3.show();
  
  Ratio mas[10];

  for(int i=0;i<5;++i){
     mas[i].input();
  }

  Ratio m1 = mas[0]; 

  for(int i=1;i<5;++i){
     if(mas[i]<m1){
        m1 = mas[i];
     }
  }

  m1.show();

  
  double eps;
  std::cin>>eps;
  int i=0;
  Ratio r;
  Ratio greg(0,1);
  do{
      r.setNom(1);
      r.setDenom(2*i+1);
      
      if(i%2==0) {
        greg = greg.add(r);
      }   
      else{
         Ratio one(-1,1);
         Ratio z = r.mult(one);
         greg = greg.add(z);
      }
     // std::cout<<"i="<<i; 
      i++;
     // r.show();
      greg.show();
  }while(!(r<eps));

  greg.show();
  Ratio four(4,1);
  greg = greg.mult(four);
  greg.show();
*/
}

