
#ifndef _POLINOM_H_
#define _POLINOM_H_

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

// P(n,x) = a_{n-1} * x^{n-1} + a_{n-2}x^{n-2} + ... +a_0
typedef double PTYPE;

class Polinom{
 
   size_t n; // power of polynome -1 (number of coef)
   PTYPE *a; //a_0, a_1 .... 
   public:
   Polinom(){n=0;}
   Polinom(size_t n);
   Polinom(size_t n, PTYPE * arr);
   ~Polinom();
   Polinom(const Polinom & p);
   Polinom & operator=(const Polinom & p);
   
   int input();    
   void output();
   int set(size_t k, PTYPE b);
   PTYPE get(size_t k);

   friend int saveFile(const char* fname, const Polinom & P);
   friend int readFile(const char* fname, Polinom & P);
   
};

#endif //_POLYNOM_H_
