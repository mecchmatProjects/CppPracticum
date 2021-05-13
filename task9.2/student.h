#pragma once
#include "human.h"

//Студент (додано: курс, група, ВУЗ)
class Student : virtual public Humanoid{
   protected:
   int kurs;
   std::string grupa;
   std::string VUZ;

   public:
   Student(){}
   Student(std::string name, unsigned age_,std::string sex,
           int kurs_,std::string grupa_,std::string VUZ_):
               Humanoid(name,age_, sex),kurs(kurs_), grupa(grupa_), VUZ(VUZ_){}

   void show();
   int input(); 
  virtual void outVUZ() {
     std::cout<<"VUz "<< VUZ;
  }
   
};




