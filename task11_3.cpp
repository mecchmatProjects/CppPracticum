

#include <iostream>
#include <list>

using namespace std;

namespace P{

  template<class T>
  class Poly{
   public:
     list<T> a;
 
     Poly(){}

     int input(int n);
     void show();

     Poly add(const Poly & p);
     Poly mult(const Poly & p);

     T value(T x);
 
  };

template<class T>
  int Poly<T>::input(int n){
    T x;
    for(int i=0;i<n;++i){
      cout<<"a["<<i<<"]=";
      cin>>x;        
      a.push_back(x);
    }
    return n;
  }

template<class T>
  void Poly<T>::show(){
    int i=0;
    typename list<T>::const_iterator it = a.begin(); 
    for(;it!=a.end();++it){
        cout<<*it<<"*x^"<<(i++)<<"+ ";      
    }
    cout<<endl;
  }

template<class T>
   Poly<T> Poly<T>::add(const Poly & p){
       typename list<T>::const_iterator it = a.begin(); 
       typename list<T>::const_iterator it2 = p.a.begin(); 
       Poly<T> res;
       while(it!=a.end() && it2!=p.a.end()){
          T c = (*it) + (*it2);
          res.a.push_back(c);
          it++;
          it2++;
       }
       if(it!=a.end()){
          while(it!=a.end()){ res.a.push_back(*it); it++;}
       }
       if(it2!=p.a.end()){
          while(it!=p.a.end()){ res.a.push_back(*it2);it2++;}
       }

     return res;
 }

 /// multiplication


 // value
template<class T>
  T Poly<T>::value(T x){

   typename list<T>::const_iterator it = a.end();
   T res=0;
   while(it!=a.begin()){
      res *= x; 
      res += *it; 
      it--;     
   }  

   return res;
 }
  

};




int main(){
  using namespace P;

  Poly<double> p1;
  Poly<double> p2;

  p1.input(3);
  p2.input(2);
  p1.show();
  p2.show();

  Poly<double> p3 = p1.add(p2);
  p3.show();
  cout<<p3.value(1);
}
