#include <iostream>
#include <queue>
#include <stack>

//#include <tchar.h> 
using namespace std; 

int main() { 
 setlocale(0,"rus"); 
 int T, N,j=1,min; 
 cout<<"input n"<<endl; 
 cin>>N; 

 queue<int> q;  

 for(int i=0;i<N;i++) { 
   cout<<"Input time"<<i<<":"; 
   cin>>T; 
   q.push(T);
 } 
/*
 min=1000; 
 for (int i=0;i<N;i++) { 
   if (T[i]<min) { 
    min=T[i];
   j=i+1; 
   } 
 } 
 cout<<"least time "<<j<<" time:"<<min<<" min"<<endl; 
 */
 stack<int> C;
 C.push(q.front());
 cout<<"1st in queue was on :"<<C.top()<<endl; 
 j=2; 
 q.pop(); 
 for (;!q.empty();j++) {
   int popered = C.top();
   int obsl = q.front();  
   q.pop();
   int c_i = popered + obsl; 
   cout<<j<<" in queue was on :"<<c_i<<"min."<<endl;
   C.push(c_i);
  
 } 
 cin.get(); 
 int i=j;
 while(!C.empty()){
    int z = C.top(); 
    C.pop(); 
    if(z<min) {
      min =z;
      i=j;
    }
    j--;

 } 
 cout<<"jmin" << j;
 cin.get();

 
 return 0; 
} 
