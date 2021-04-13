
/*
Напишіть функцію, що приймає рядок та повертає масив заданої довжини n (як
аргумент-змінний) перші n дійсних чисел, що містяться в рядку. Роздільник
задається як аргумент функції 
*/
#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

int array_doubles(const string str, string delimeter, double* arr, int m){
   
   size_t i=0;
   size_t n = str.length();
   while(i<n && delimeter.find(str[i])!=string::npos){
      i++;
   }
   
   if(i>=n){
       return 0;
   } 

   int j=0;
   string res;
   while(j<m && i<n){
   	res = "";
   	//cout<<i<<","<<j<<"\t";
  	 while(i<n && delimeter.find(str[i])==string::npos){
   	   res.push_back(str[i]);
    	  i++;      
  	 }
   cout<<"res="<<res;

   arr[j] = atof(res.c_str()); // c++11 - stod()
   j++; 

   while(i<n && delimeter.find(str[i])!=string::npos){
      i++;
   }

   }
   return j;
}



int main(){
 double a[10];
 cout<< array_doubles(string("  1.234 345,-45.56 1.")," ,",a,4)<<endl;
 for(int i=0;i<4;i++){
   cout<<a[i]<<" ";
 } 
 string inp; 
 getline(cin,inp);

 int r = array_doubles(inp," ,:",a,5);
 cout<<"doubles:"<< r<<endl;
}
