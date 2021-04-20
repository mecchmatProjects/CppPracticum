
/*
 class rational number

*/

#include <iostream>


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

   Ratio(int x, unsigned y): nominator(x),denominator(y){} 

   void show(){
      std::cout<<nominator<<"/"<<denominator<<std::endl;
   }

   int input(){
      std::cout<<"n/m=";
      std::cin>>nominator>>denominator;
   }

   void setNom(int nominator){
         this->nominator = nominator; 
   }

   int setDenom(unsigned y){
       if(y==0) { denominator = 1; return -1;}
       denominator = y;
       return 0;
   }
     
   // multiplication
   Ratio mult(const Ratio& other);
   //addition

   Ratio add(const Ratio& other);

   unsigned gcd(unsigned x, unsigned y);//Greatest Common Divisor

   void reduce();


  bool operator< (const Ratio& a){
     return nominator*a.denominator < denominator * a.nominator;
  }

   bool operator< (double eps){
     return double(nominator)/denominator <eps;
  }
};


Ratio Ratio::add(const Ratio& other){
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
  Ratio p4,p3 = p1.add(p2);
  p3.show();
  p4 = p1.mult(p2);
  p4.show();
  
  std::cout<<std::boolalpha<<(p4<p3);
  /*
  Ratio r1,r2,r3;

  r1.input();
  r1.show(); 

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

  */
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
}

