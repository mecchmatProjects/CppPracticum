//#ifdef
#pragma once
#include <iostream>
#include <string>
#include <cctype>


/*
#include <algorithm>
int tol(std::string & str){
  //std::transform(str.begin(),str.end(),str.begin(),[](char x)->char {return tolower(x);});
  std::transform(str.begin(),str.end(),str.begin(),tolower);
  return 0;
}*/


class Humanoid{
   protected:
   std::string pib;
   unsigned age;
   bool gender; 

   public:
     Humanoid(){}
     Humanoid(std::string name, unsigned age_,std::string sex);

     virtual void show();
     
     int input();

     virtual void outVUZ() = 0; // pure virtual
};



