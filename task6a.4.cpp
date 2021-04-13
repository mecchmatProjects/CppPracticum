 
/*
 task 14.4, 6.4
 Ввести рядок, що складається з символів латинського алфавіту,слова в якому
  відокремлені пробілами (одним або декількома). Перетворити кожне слово в
  рядку, видаливши з нього всі входження останньої літери цього самого
  слова (кількість пробілів між словами не змінювати).
*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;


string rem(string s, char c, int start, int len){
   string res=s.substr(0,start);
   for(int i=start;i<=start+len;++i){
       if(s[i]==c) continue;
       res += s[i];
   }
   //res += s.substr(start+len,s.length());
   return res;
}


string sl_word(const string& s){
   int start=0;
   int fin=0;
   bool space=true;
   string res = s;
   string word =""; 
   int k=0;
   for(size_t i=0;i<=s.size();i++){
       //if(s[i]==' ' || s[i]=='\0') {
       if(isspace(s[i]) || s[i]=='\0'){ 
           if(!space){
              fin=i-1;
              res = rem(res + s.substr(start, fin-start),s[i-1],k,fin-start);
              //res +=" ";
              k = res.length();  
              
           }
          res +=" ";  
          space = true;
       }
       else{
           if(space){
              start=i;
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
  string k = sl_word(inp_str);

  cout<< "\n The words without end = "<<k<<endl;
}
