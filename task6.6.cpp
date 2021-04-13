
/*
Напишіть функцію часткового спліттінгу рядку, тобто функцію, що
приймає рядок та повертає першt слово з рядку (роздільник задається
як аргумент функції). 
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string first_word(const string str){
   
   size_t i=0;
   size_t n = str.length();
   while(i<n && !isalpha(str[i])){
      i++;
   }
   
   if(i>=n){
       return "";
   } 

   string res="";
   while(i<n && isalpha(str[i])){
      res.push_back(str[i]);
      i++;
   }
   return res;
}



string first_word(const string str, string delimeter){
   
   size_t i=0;
   size_t n = str.length();
   while(i<n && delimeter.find(str[i])!=string::npos){
      i++;
   }
   
   if(i>=n){
       return "";
   } 

   string res="";
   while(i<n && delimeter.find(str[i])==string::npos){
      res.push_back(str[i]);
      i++;
   }
   return res;
}

int main(){

 cout<< first_word(string("  dsf fsdf f")," ,.")<<endl;

 string inp; 
 getline(cin,inp);

 string r = first_word(inp," ,.:");
 cout<<"first word:"<< r<<endl;
}
