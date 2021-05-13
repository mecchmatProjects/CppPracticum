
#include "student.h"
#include "lecturer.h"
#pragma once

//додано: ВУЗ, посада,  з.п
class PostGrad : public Lecturer, Student{
 

   public:
   PostGrad(){}
   PostGrad(std::string name, unsigned age_,std::string sex,
           std::string VUZ_, std::string pos, double zp,
           int kurs_, std::string grupa):
               Lecturer(name,age_, sex,VUZ_,pos,zp){
               kurs = kurs_; this->grupa = grupa;  
            }

   void show();
   int input(); 


  void outVUZ() {
     std::cout<<"VUZ "<< VUZ1;
  }
   
};




