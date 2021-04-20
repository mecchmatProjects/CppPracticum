#include <iostream>
#include <string> 

using namespace std;
 
int array_doubles(const string str, const string delimeter, double* arr, int n) { 
 int i=0; int len = str.length(); 
 cout << len << endl; 
 while(i<len){ 
    cout<<str[i];
    if(!isspace(str[i]) || delimeter.find(str[i])==string::npos){ break; } 
   i++; 
 } 
cout <<"l="<< i << endl; 
if(i>=len){ return 0; } 
int counter = 0; 
string temp = ""; 
while(i<=len){ 
     
     if(delimeter.find(str[i])!=string::npos || i == len){
      cout<<"t="<<temp;
        //if(counter < n) arr[counter] = stof(temp);//c++11
        if(counter < n) arr[counter] = atof(temp.c_str());
     cout <<"r="<< stof(temp) << endl; 
     temp = ""; 
    counter++; 
    i++; 
   } 
 else{ 
  temp.push_back(str[i]); 
  i++; 
 } 
 } 
 return counter; 
} 
int main() { 
 string my_str = " 14.5,56.12 67.7"; 
 char delimiter; 
 double arr[10]; 
 int n=3; 
 int k=array_doubles(my_str, " ,", arr, n); 
 cout << endl; 
 for(int i=0; i<k; i++){ 
 cout << arr[i] << endl; 
 } 
return 0; } 
