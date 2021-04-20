/*  У текстовому файлі, що складається зі слів, відокремлених одним пропуском,
  замінити першу літеру у словах, що йдуть за словами die, der, das, на
  відповідну літеру верхнього регістру.*/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

void trim(string& s, const string delimeters=" ,;&?:!."){
    // delete extra delimeters from word
   int i=0;
   size_t len = s.length();
   while(i<len){
     if(delimeters.find(s[i])==string::npos) break;
     //if(isspace(s[i]))  
     i++;
   }
   s.erase(0,i);
   i = s.length()-1;
   while(i>=0){
     if(delimeters.find(s[i])==string::npos) break;
     i--;
   }
   s.erase(i+1,s.length());
}

void inversia(string& s){
   size_t n = s.length();
   for(int i=0;i<n/2;i++){
      char tmp = s[i];
      s[i] = s[n-1-i];
      s[n-1-i] = tmp;
   }

}

string inversia1(const string& s){
   size_t n = s.length();
   string res(s);
   cout<<"s="<<s;
   for(int i=0;i<=n;i++){
      res[i] = s[n-1-i];
   }
  cout<<"r="<<res;
   return res;
}

int main(){

 ifstream f("shifr.txt");

 string buf;
 bool art = false; 

 ofstream f2("decript.txt"); 
 while(f>>buf){
    cout<<"buf="<<buf<<"\n";
     trim(buf);
     inversia(buf);

     f2<<buf<<" ";
 } 

 f.close(); 
 f2.close();
}
