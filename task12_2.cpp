

#include <iostream>
#include <set>

template<class T>
int input_set(std::set<T> &s){
   int k = 0; 
   int x;
   do{
     std::cin>>x;
     if(x==0) break;
     s.insert(x);
     k++;
   } while(true);
  return k;
}

template<class T>
T rec_add(std::set<T> & s){

   typename std::set<T>::iterator it=s.begin();  
   T x=0;
   int k=0;
   if(s.size()==1){
      return *it;
   }   

   std::set<T> s1;
   
   for(;it!=s.end();++it){
      x += *it;
      if(k%2){
        std::cout<<"x="<<k<<","<<x<<"\n"; 
        s1.insert(x);
        x=0;
      } 
      k++;
   }
   if(k%2){
     std::cout<<"x="<<k<<","<<x<<"\n"; 
     s1.insert(x);
   }
   return rec_add(s1);
}


int main(){

  std::set<int> s; 
  int k = input_set(s);
  std::cout<<k<<" elements were input\n";
  
  int sum1 = rec_add(s); 

  std::cout<<"s="<<sum1;
}
