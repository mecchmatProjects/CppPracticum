
/*

Реалізуйте запропоновані методи (можете додати ще власних) та зробіть
для класу перевантаження стандартних операторів вводу-виведення.

Описати клас Знайомий на базі класу Person. У цьому класі повинно бути 
як мінімум одне додаткове поле «номер телефону»,
 а також методи введення та виведення інформації про знайомого. 
Використати цей клас для побудови класу телефонного довідника (кількість
знайомих обмежена числом 100). Передбачити дії: створення довідника, додавання запису про знайомого,
пошуку номера телефону за прізвищем та заміни номера телефону. 
Телефонний довідник зберігає дані про знайомих у файлі.
\emph{\emph{Вказівка}}: телефонний довідник представити у вигляді класу,
що зчитує дані з (текстового) файлу.

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Person{ 
 protected: 
  //Клас Особа
  string name; //прізвище
  unsigned byear; //рік народження
public:
 int input(); //ввести особу  
 void show(); //вивести особу
};

int Person::input(){
  cout<<"Input person(name, year):\n";
  cin>>name;
  cin>>byear;
  return 0;
}

void Person::show(){
  cout<<"Person "<<name<<", "<<byear;
}

class Acquanted : public Person{
   string tel;
   public:
   
   int setTel(string s){
     tel = s;
   }
   string getTel(){
     return tel;
  }

   string getName(){
       return name;
   }
   int getYear(){
      return byear;
   }

  void show(){
  cout<<"Acqainted "<<name<<", "<<byear<<", "<<tel;
 }

 int input(){ Person::input(); cout<<"phone:"; cin>>tel; }   
 
 /*friend ifstream& operator>>(ifstream& f, Acquanted & a){
     f>>a.name>>",">>a.byear>>",">>a.tel;
  }*/ 

};


class Phonebook{

   string filename;
   fstream fp;
   public:

   int setFile(string s){
       filename = s;
   } 

   int addAcquanted(Acquanted& x){
      fp.open(filename.c_str(), ios::app);
      cout<< x.getName()<<","<<x.getYear()<<","<<x.getTel()<<"\n";
      fp<<x.getName()<<","<<x.getYear()<<","<<x.getTel()<<"\n";
      fp.close(); 
   }

   string getTelByName(string name){
      fp.open(filename.c_str(), ios::in);
      Acquanted x; 
      string str;
      while(getline(fp,str)){
          size_t k = str.find_first_of(",");
          string nm = str.substr(0,k);
          cout<<nm;
          size_t k2 = str.find_last_of(",");  
          string t = str.substr(k+1,k2); 
          if(nm==name){
              fp.close();
              return t;
          }
      }
      cout<<"No name "<<name<<" was found";
      fp.close();
      return string("None");
       
   }

};

int main(){
   Person p;
   //p.input();
   //p.show();

   Phonebook ph;
   ph.setFile(string("hpones.txt"));
   int n;
   cin>>n;
   for(int i=0;i<n;++i){

      Acquanted a;
      a.input();
      /*string t1;
      cout<<"input teleph";
      cin>>t1;
      a.setTel(t1); */
      a.show();
      ph.addAcquanted(a);
   }

   string t = ph.getTelByName("Vasya");
   cout<<t;
}

