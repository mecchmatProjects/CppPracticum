
#ifndef _POLYNOM_H_
#define _POLYNOM_H_

//#pragma once

/*
 Визначить клас Поліном, що ініціалізується кількістю елементів масиву
  N та виділяє при цьому пам'ять під N дійсних чисел. Створіть методи
  для заповнення членів цього масиву (через конструктор та окремим
  методом) та конкретного коефіцієнту за номером. Визначить деструктор
  та копіконструктор. 

  Визначить свою дружню функцію для цього класу для введення/виведення
його з консолі у бінарний файл.

*/

class Polynom{
   size_t n; 
   double *p;
   
   public:
   Polynom(){n=0;}
   Polynom(size_t n);

   Polynom(size_t n, double *arr); // P(2,1.0,1.0);

   ~Polynom();

   Polynom & operator=(Polynom a);
 
   Polynom(const Polynom & p);

   int set(size_t k, double a); //P.set(1,2.0) -> p[1] = 2.0

   double get(size_t k);

   void show();

   friend int saveFile(const char* fname,const Polynom & P);
   friend int readFile(const char* fname,Polynom & P);

   friend void swap(Polynom& first, Polynom& second) // nothrow
    {
        // enable ADL (not necessary in our case, but good practice)
        using std::swap;

        // by swapping the members of two objects,
        // the two objects are effectively swapped
        swap(first.n, second.n);
        swap(first.p, second.p);
    }

};

#endif //_POLYNOM_H_
