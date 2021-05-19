

#include <iostream>
#include <fstream>

#include <sstream>

#include <map> 	
#include <vector>
 	
#include <string> 
#include <cstdlib> 
#include <cmath> 
using namespace std;

int main(){
   
  ifstream in("points12.txt");
  if (!in) { cerr << "File not found\n"; exit(1);}

  string s;

  map<double, string> segm;

  vector<int> v1;
  vector<int> v2;
 
  while (in >> s){
    //cout<<"s="<<s;
    //s.erase(0,1);
    int n = s.length();
    s.erase(n-1,n); 
    int r = s.find_first_of(",");
    string x1 = s.substr(1,r);
    string x2 = s.substr(r+1,n-1);
    //cout<<"s1="<<x1;
    //cout<<"s2="<<x2;
    int y1,y2;
    stringstream s1;
    s1<<x1;
    s1>>y1;
    stringstream s2;
    s2<<x2;
    s2>>y2;
    
    cout<<"y1,y2"<<y1<<y2; 
    v1.push_back(y1);
    v2.push_back(y2);
  }
  
  for(int i=0;i<v1.size();i++){
     int x1 = v1[i];
     int y1 = v2[i];
 
     for(int j=i;j<v2.size();j++){
       int x2 = v1[j];
       int y2 = v2[j];
       double len = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
       // convert segment to string
       stringstream tmp;
       tmp<<"("<<x1<<","<<y1<<")-("<<x2<<","<<y2<<"),";
       std::string tmp2;
       tmp>>tmp2;
       // add into map
       segm[len] = tmp2;  
     }
  }
  // write values to file
  ofstream out("segm12.txt",ios::out);
  for(map<double,string>::const_iterator it = segm.begin();it!=segm.end();++it){
     out<<it->second;
  }

  out.close();



}
