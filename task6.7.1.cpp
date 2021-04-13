#include <iostream>
#include <string> 
using namespace std; 
string array_doubles(const string str, string delimeter, double* arr, int n) { 
 int i=0; int len = str.length(); 
 cout << len << endl; 
 while(i<len){ 
    if(!isspace(str[i])){ break; } 
   i++; 
 } 
cout << i << endl; 
if(i>=len){ return ""; } 
int counter = 0; 
string temp = ""; 
while(i<=len){ 
     if(delimeter.find(str[i])!=string::npos || i == len){
        if(counter < n) arr[counter] = stof(temp);
     //cout << stof(temp) << endl; 
     temp = ""; 
    counter++; i++; 
   } 
 else{ 
  temp.push_back(str[i]); i++; 
 } 
 } 
 return ""; 
} 
int main() { 
 string my_str = " 14.5,56.12 67.7"; 
 char delimiter; 
 double arr[10]; 
 int n=3; 
 array_doubles(my_str, " ,", arr, n); 
 cout << endl; 
 for(int i=0; i<n; i++){ 
 cout << arr[i] << endl; 
 } 
return 0; } 
