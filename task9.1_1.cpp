
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
#include <cstdio>
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
   private:
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
   
   int startNew(){
     return remove(filename.c_str());
   }

   int addAcquanted(Acquanted& x){
       fp.open(filename.c_str(),ios::app|ios::binary);
       if(fp.bad()){
         cerr<<"error opening "<<filename;
         return -1;
       }
       fp.write((char*)&x,sizeof(x)); 
       fp.close();      
      
       return 0;
   }


 int addAcquanted2(Acquanted& x){
       FILE * fp = fopen(filename.c_str(),"ab");
       if(fp==NULL){
         cerr<<"error opening "<<filename;
         return -1;
       }
       fwrite((char*)&x,sizeof(x),1,fp); 
       fclose(fp);      
      
       return 0;
   }
   
   string getTelByName(string name){
       fp.open(filename.c_str(),ios::in|ios::binary);
       if(fp.bad()){
         cerr<<"error opening "<<filename;
         return "Error";
       }
       cout<<"\n\n\n"; 
       Acquanted* x = new Acquanted();
       while(!fp.eof()){

          fp.read((char*)x,sizeof(*x));
          cout<<"working"; 
          
         //cout<<"working"<<sizeof(*x); 
          cout<<"\np="; 
          x->show();
        
          if (x->getName()==name){
              cout<<"Found "<<name;
              fp.close();         
              return x->getTel();
          }
       }      
       fp.close(); 
       cout<<"Not found";
      return string("None");
       
   }

string getTelByName2(string name){
       FILE * fp = fopen(filename.c_str(),"rb");
       if(fp==NULL){
         cerr<<"error opening "<<filename;
         return "Error";
       }
       cout<<"\n\n\n"; 
       Acquanted y;
       Acquanted* x = &y;//!!!!!
       while(!feof(fp)){

          ///fp.read((char*)x,sizeof(*x));
          
          cout<<"working"<<fread(x,sizeof(*x),1,fp); 
          
         //cout<<"working"<<sizeof(*x); 
          cout<<"\np="; 
          x->show();
        
          if (x->getName()==name){
              cout<<"Found "<<name;
              fclose(fp);         
              string res = x->getTel();

              return res;
          }
       }      
       fclose(fp); 
       //delete x;
       cout<<"Not found";
      return string("None");
       
   }

};

int main(){
   Person p;
   //p.input();
   //p.show();

   Phonebook ph;
   ph.setFile(string("phones3.dat")); 
   ph.startNew();
   int n;
   cout<<"n=";
   cin>>n;
   Acquanted a;
   for(int i=0;i<n;++i){


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

