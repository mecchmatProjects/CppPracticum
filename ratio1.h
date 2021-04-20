
#ifndef _RATIO1_H_
#define _RATIO1_H_
//#pragma once

#include <iostream>
#include <cmath>
using namespace std;

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
      reduce();
   }
   //Rat(int x, unsigned y){ nominator=x;denominator =y;}


   int input(){
       cout<<"Input n,m:";
       cin>>nominator>>denominator;
    }

   void output(){
     cout<<nominator<<"/"<<denominator<<endl;
   }

   void setNom(long long int nominator){
        this->nominator = nominator; //   
   }

   int setDenom(long long unsigned denominator){
      if(denominator==0) return -1;
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

   bool greaterReal(double eps){
        return (double)nominator/denominator>eps;
   }

   double value12(){
       return sqrt(12.0*(double)nominator/denominator);
   }
   
};



#endif //_RATIO1_H_
