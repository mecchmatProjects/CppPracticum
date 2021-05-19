
#include <iostream>
#include <list>

using namespace std;

namespace P{
 
   template<class T>
   class Poly{
      list<T> a;
     public:
     Poly<T>() = default;
     Poly<T>(const Poly<T> &) = default;
     int input(int n);

     friend ostream & operator<<(ostream & out, const Poly<T> & p){
        int i=0;
        out<<"P=";
        for(auto it=p.a.cbegin(); it!=p.a.cend();++it){
           //cerr<<i<<*it;
           out<<(*it)<<"*x^"<<(i++)<<" + ";
        }
        out<<endl;
        return out;
     }

     T value(T x){
         T res =0;
         for(auto it=a.cend(); it!=a.cbegin();--it){
           res *= x;
           res += *it;
        }
        return res;
     }     

     Poly<T> add(const Poly<T> & other);     
   };

   template<class T>
   int Poly<T>::input(int n){
      T x;
      cout<<"Poly\n";
      for(int i=0;i<n;++i){
         cout<<"\na "<<i<<":";
         cin>>x;
         a.push_back(x);
      }
      return n;
   }

  template<class T>
   Poly<T> Poly<T>::add(const Poly<T> & other){
    size_t n = a.size();
    size_t m = other.a.size();  
    Poly<T> res;
    cerr<<"sizes"<<n<<m;
    if(m<n){
       typename list<T>::iterator it = a.begin(); 
       auto it2 = other.a.begin(); 
       for(;it2!=other.a.end();++it2,++it){
           res.a.push_back(*it + *it2); 
       }
       for(;it!=a.end();++it){
           res.a.push_back(*it); 
       }
    }
    else{
       auto it = a.begin(); 
       auto it2 = other.a.begin(); 
       for(;it!=a.end();++it2,++it){
           res.a.push_back(*it + *it2); 
       }
       for(;it2!=other.a.end();++it2){
           res.a.push_back(*it2); 
       }
   }

    return res;
  }     

}

int main(){

  using namespace P;

  Poly<double> p1,p2,p3;

  p1.input(2);
  p2.input(3);
  cout<<p1;
  cout<<p2<<p2.value(1);
  p3 = p1.add(p2);
  cout<<p3<<p3.value(1);

}

