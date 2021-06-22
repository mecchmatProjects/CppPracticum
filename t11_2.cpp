#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){

 int n;
 cin>>n;
 int t;
 queue<int> q1;
 for(int i=0;i<n;++i){
    cin>>t;
    q1.push(t);
 }

 vector<int> c;
 int time=0;
 while(!q1.empty()){
   t=q1.front();
   q1.pop();
   time += t;
   c.push_back(time);   
 }
 cout<<endl;
 /*for(int i=0;i<c.size();++i){
  cout<<c[i]<<", ";
 }*/

  for(vector<int>::iterator it=c.begin();it!=c.end();++it){
   cout<<*it<<", ";
  }

}
