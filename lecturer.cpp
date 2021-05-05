

#include <iostream>
#include <string>
#include <cctype>

#include "lecturer.h"


void Lecturer::show(){
       std::cout<<pib<<", age "<<age<<", "<< (gender?"male":"female")<<"\n";
       std::cout<<posada<<", "<< VUZ1<<"\n";
     }
     
int Lecturer::input(){
     Humanoid::input();
     std::cout<<"Vuz,posada, z/p:";
     std::cin>>VUZ1;
     std::cin>>posada;
     std::cin>>salary;  
}

/*
int main(){
  // std::string s("FFFFhhjH"); 
  // tol(s);
  // std::cout<<s;
   Lecturer s1(std::string("vasya"),33,std::string("male"), "KNU", "Docent", 345.67);
   Lecturer s2;
   try{
    s2.input();
   }
   catch(const char* s){
   std::cout<<"Incorrect gender";
  }
   s1.show();
   s2.show();
}*/

