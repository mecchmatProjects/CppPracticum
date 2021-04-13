/*
  Даний рядок -- речення з символів латинського алфавіту. Вивести
  найкоротше слово в реченні. Якщо таких слів декілька, то: 
  а) вивести перше з них; б) останнє з них; в) всі такі слова.
*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;

string shortword(const string& s){
 
 bool space=true;
 string res; 
 int start=0;
 int fin=-1; 
 int minLen = INT_MAX;
 int wlen;
 int st,fn;
 for(size_t i=0;i<=s.size();i++){
       if(s[i]==' ' || s[i]=='\0') {
           if(!space){
              fin = i-1;    
              if(fin>0){
                 wlen = fin - start;
                 //clog<<"Str"<<start<<","<<fin<<"w="<<wlen<<endl;
                 if(wlen<minLen){
                    minLen = wlen;
                    st = start;
                    fn = fin; 
                 }        
                 //clog<<"Min"<<st<<","<<fn<<"w="<<minLen<<endl;  
              }
           }
          space = true;
       }
       else{
           if(space){
              start=i; 
           }
          space = 0;  
       }   
   }

  res = s.substr(st,fn-st+1); // start, start + len
  //clog<<"Subs"<< res<<endl;
  return res;

}

int main(){

  string inp_str;//("fsdfsdf fdff fdfdsfsdf ffffffs");
  
  //cin>>inp_str;
  getline(cin, inp_str);
  
  cout<<inp_str; 
  string k = shortword(inp_str);

  cout<< "\n The words with sama start/end = "<<k<<endl;
}
