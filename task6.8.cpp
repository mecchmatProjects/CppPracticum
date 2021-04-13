/*  У текстовому файлі, що складається зі слів, відокремлених одним пропуском,
  замінити першу літеру у словах, що йдуть за словами die, der, das, на
  відповідну літеру верхнього регістру.*/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

void inversia(string& s){
   size_t n = s.length();
   for(int i=0;i<n/2;i++){
      char tmp = s[i];
      s[i] = s[n-1-i];
      s[n-1-i] = tmp;
   }

}

int main(){

 ifstream f("shifr.txt");

 string buf;
 bool art = false; 

 ofstream f2("decript.txt"); 
 while(f>>buf){
  //  cout<<"buf"<<buf;
     inversia(buf);
     f2<<buf<<" ";
 } 

 f.close(); 
 f2.close();
}
