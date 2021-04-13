/*  У текстовому файлі, що складається зі слів, відокремлених одним пропуском,
  замінити першу літеру у словах, що йдуть за словами die, der, das, на
  відповідну літеру верхнього регістру.*/

#include <iostream>
#include <fstream>
#include <cctype>

using namespace std;

int main(){

 ifstream f("deutsch.txt");

 string Artikles[] = {"der", "das", "die", "dem"};

 string buf;
 bool art = false; 

 ofstream f2("deutsch2.txt"); 
 while(f>>buf){
  //  cout<<"buf"<<buf;

    if(art) {
       buf[0] = toupper(buf[0]);
    }
    cout<<buf<<" ";
    f2<<buf<<" ";

    art =false; 
    for(int i=0;i<4;i++){
       if(buf==Artikles[i]){
          art = true;
          break;
       }
    }  
   
 } 

 f.close(); 
 f2.close();
}
