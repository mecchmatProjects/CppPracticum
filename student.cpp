

#include <iostream>
#include <string>
#include <cctype>

#include "student.h"


void Student::show(){
       std::cout<<pib<<", age "<<age<<", "<< (gender?"male":"female")<<"\n";
       std::cout<<kurs<<", "<<grupa<<", "<< VUZ<<"\n";
     }
     
int Student::input(){
     Humanoid::input();
     std::cout<<"Kurs, grupa, Vuz:";
     std::cin>>kurs;
     std::cin>>grupa;
     std::cin>>VUZ;
}

/*
int main(){
  // std::string s("FFFFhhjH"); 
  // tol(s);
  // std::cout<<s;
   Student s1(std::string("vasya"),33,std::string("male"), 3, "stat1","KNU");
   Student s2;
   try{
    s2.input();
   }
   catch(const char* s){
   std::cout<<"Incorrect gender";
  }
   s1.show();
   s2.show();
}
*/
