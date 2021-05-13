

#include <iostream>
#include <string>
#include <cctype>

#include "human.h"

/*
#include <algorithm>
int tol(std::string & str){
  //std::transform(str.begin(),str.end(),str.begin(),[](char x)->char {return tolower(x);});
  std::transform(str.begin(),str.end(),str.begin(),tolower);
  return 0;
}*/

 Humanoid::Humanoid(std::string name, unsigned age_,std::string sex):
             pib(name){
                   age = age_;
                   if(sex=="male") {gender = false;}
                   else if (sex=="female"){ gender= true; } 
                   else {
                       throw "Incorrect Gender";
                   }
             }

 void Humanoid::show(){
       std::cout<<pib<<", age "<<age<<", "<< (gender?"male":"female")<<"\n";
     }
     
int Humanoid::input(){
       std::cout<<"Input name, age, gender";
       std::cin>>pib;
       std::cin>>age;
       std::string sex;
       std::cin>>sex;
       if(sex.length()>0){
         char c = tolower(sex[0]);
         if(c='m') gender = false;
         else if (c=='f' || c=='w') gender = true;
         else throw "Incorrect Gender";   
       } 
       else{
          throw "Incorrect Gender";
       }
  
}

/*
int main(){
  // std::string s("FFFFhhjH"); 
  // tol(s);
  // std::cout<<s;
   Humanoid h1(std::string("vasya"),33,std::string("Male"));
   Humanoid h2;
   try{
    h2.input();
   }
   catch(const char* s){
   std::cout<<"Incorrect gender";
  }
   h1.show();
   h2.show();
}
*/
