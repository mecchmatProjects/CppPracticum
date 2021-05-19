

#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>

using namespace std;

int main(){
  
  vector< vector<int> > matr;
  
  int n,m;

  cin>>n;
  cin>>m;

  for(int i=0;i<n;++i){
    vector<int> v;
    double x; 
    for(int j=0;j<m;++j){
       cout<<"a["<<i<<","<<j<<"]=";
       cin>>x;
       v.push_back(x);
    } 
    matr.push_back(v);
  }

  list<pair<int,int> > max_row;
  int i=0; 
  for(vector<vector<int> >::iterator it = matr.begin(); it!=matr.end();++it,++i){
     int mr = *max_element(it->begin(),it->end());
     max_row.push_back(make_pair(mr,i)); 
  } 

  max_row.sort();

  list<pair<int,int> >::iterator it = max_row.begin();
  for(int i=0;i<n;++i){
     vector<int> r = matr[i] ;
     int j= it->second;
     matr[i] = matr[j] ;
     matr[j] = r;
  } 

 for(int i=0;i<n;++i){
    for(int j=0;j<m;++j){
       cout<<matr[i][j]<<",";
    } 
    cout<<endl;
  }

  

}

