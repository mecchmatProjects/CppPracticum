
/*
 Перевірте у текстовому файлі правильність
  розстановки тегів <td>: кожному відкритого тегу
  повинен відповідати закритий </td>.
*/
#include <iostream>
#include <fstream>

using namespace std;


bool checkTags(ifstream& f1, string openTD = "<td>", string closeTD = "</td>"){

  int opentag =0;
  int closetag =0;
  
  string buf;
  while(!f1.eof()){
     if(f1>>buf){
        //cout<<buf<<"\n";
        if(buf==openTD) {
           //cout<<"TD!";
           opentag++;
        }
        else if (buf==closeTD){
          //cout<<"DT!";
          closetag++; 
       }
       if(closetag>opentag) return false;
     }
     else{
       break;
    }
  }
  return closetag==opentag;
}



int main(){

  const char * fname = "t63.txt";
  ifstream f1(fname);
  
  if(f1.bad()){
   cerr<<"error opening"<<fname<<endl;
  }
  
  cout<<"\n Check "<<boolalpha<<checkTags(f1); 

  f1.close();

}
