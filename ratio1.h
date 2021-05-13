
#ifndef _RATIO1_H_
#define _RATIO1_H_
//#pragma once

#include <iostream>
#include <cmath>

#include <exception>

using namespace std;


class ZeroDenominator : public exception{
   public:
   const char* what(){
       return "Denominator should be non zero!";
   }
};


//struct
class Rat{
   private:
   //public: 
   long long int nominator;
   long long unsigned denominator;

   //
   public:

   Rat(){nominator=1; denominator=1;}

   Rat(long long int x, long long unsigned y): nominator(x),denominator(y){
      if(denominator==0) { // denominator <> 0 !!! exception
           throw ZeroDenominator();
       }
      reduce();
   }
   //Rat(int x, unsigned y){ nominator=x;denominator =y;}


   int input(){
       cout<<"Input n,m:";
       cin>>nominator>>denominator;
       if(denominator==0) { // denominator <> 0 !!! exception
           throw ZeroDenominator();
       }
    }

   void output(){
     cout<<nominator<<"/"<<denominator<<endl;
   }

   void setNom(long long int nominator){
        this->nominator = nominator; //   
   }

   int setDenom(long long unsigned denominator){
       if(denominator==0) { // denominator <> 0 !!! exception
           throw ZeroDenominator();
       }
      this->denominator = denominator; //   
      return 0; 
   } 

   Rat add(const Rat & other); // addition z = x.add(y); // x+y

   Rat mult(const Rat & other);
  // subtraction, division
   Rat division(const Rat &other);
   Rat subtraction(const Rat &other);

   void reduce();

   bool less(const Rat& r);

   bool operator>(const Rat & r) {
    return (nominator*r.denominator > denominator*r.nominator); 
   }

   bool greaterReal(double eps){
        return (double)nominator/denominator>eps;
   }

   double value12(){
       return sqrt(12.0*(double)nominator/denominator);
   }

   

  friend int saveToFile(const char* fname, const Rat & r);
  friend int readFromFile(const char* fname, Rat & r);
  
};



#endif //_RATIO1_H_
