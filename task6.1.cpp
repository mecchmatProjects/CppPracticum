 
/*
 task 14.1, 6.1
Даний рядок, що складається з символів латинського алфавіту, слова в якому
  відокремлені пробілами (одним або декількома). Визначити кількість слів,
  які починаються і закінчуються однією і тією ж літерою.
*/
#include <iostream>
#include <string>

using namespace std;


int sl_word(const string& s){
   char start=0;
   char fin=0;
   bool space=true;
   int res = 0; 
   for(size_t i=0;i<=s.size();i++){
       if(s[i]==' ' || s[i]=='\0') {
           if(!space){
              fin=s[i-1];
              if(fin==start) {
                   res++;
              } 
           }
          space = true;
       }
       else{
           if(space){
              start=s[i]; 
           }
          space = false;  
       }   
   }
  return res;
}


int main(){

  string inp_str;
  
  //cin>>inp_str;
  getline(cin, inp_str);
  cout<<inp_str; 
  int k = sl_word(inp_str);

  cout<< "\n The words with sama start/end = "<<k<<endl;
}
