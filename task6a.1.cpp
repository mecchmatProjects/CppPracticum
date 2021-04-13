
/*
Передумова:
В даній групі задач потрібно реалізувати функції та в тих функціях де
потрібно виводити рядок зробіть 2 варіанти: 
результат записати в новий рядок; 
результат замінює рядок, що є аргументом функції. 
В даному рядку знайти підядок який знаходиться між першою 
двокрапкою та наступню за нею комою. 
*/

#include <iostream>
#include <string>

using namespace std;

string semicoma(const string& s){
   
   size_t p1 = s.find(":"); // find
   if(p1==string::npos){
      return s;
   }
  
   size_t p2 = s.find(",",p1+1);
   if(p2==string::npos){
      return s.substr(p1+1,s.length()-p1);
   }   
   return s.substr(p1+1,p2-p1-1);
}



int semicoma2(string &s){

   size_t p1 = s.find(":");
   if(p1==string::npos){
      return 0;
   }
  
   s.erase(0,p1+1);
   size_t p2 = s.find(",");
   if(p2==string::npos){
      return 1;
   }

  s.erase(p2,s.length()-p2);
  return 2;
}

int main(){


   string test[] ={"fgdsf:fsdgdsafgd,sdgdsg", "dsfgsd:gdsfg", "fdgdsfg"};
 
   for(int i=0;i<3;++i){
       string s1 = semicoma(test[i]);
       cout<<s1<<endl;
   }


   string s;
   cin>>s;   

   string s1 = semicoma(s);
   cout<<s1<<endl;

   semicoma2(s); 
   cout<<s<<endl;
}
