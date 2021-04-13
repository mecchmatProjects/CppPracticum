#include <iostream> 
#include <string> 
#include <fstream> 
using namespace std; 
bool sl_word(string &s){ 
bool start_tag;
  for(size_t i=0; i<s.length()-3; i++) {
      //if(s[i]=='<' && s[i+1]=='t' && s[i+2]=='d' && s[i+3]=='>') { 
       //size_t pos = s.find("<td>");          
        string buf = s.substr(i,3);
       if(buf=="<td>"){  
        cout << "Zdarowa" << endl; 
        start_tag = true; 
       } 
      else{ 
       if(start_tag && s[i]=='<' && s[i+1]=='/' && s[i+2]=='t' && s[i+3]=='d' && s[i+4]=='>')
         { cout << "Close tag found" << endl; 
          start_tag = false; 
         } 
       } 
    } return start_tag; 
 } 
int main() {
      ifstream File("file.txt"); string str; 
     bool only_start_tag; 
    while (getline (File, str)) { 
       only_start_tag = sl_word(str); 
     // cout << str << endl; 
    } 
   if(only_start_tag) { 
     cout << "Not enough end tags"; 
  } 
 return 0; 
} 
