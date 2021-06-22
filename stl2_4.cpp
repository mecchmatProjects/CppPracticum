

#include <iostream>

#include <map>
#include <string>
#include <vector>

std::vector<int> decimal (int n){
   std::vector<int> res;

   while(n){
      int p = n%10;
      res.push_back(p);
      n /=10;
   }
   return res;
}


int f(int n){

    
  std::string least[10] = {"odyn","dva","try","40tyry","p'yat","6ist","sim","visim","dev'yt'"};
  std::string dec[10] = {"nadzyat'","dvadzyat","trydyzat","sorok","p'yatdesyt","6istdesyt","simdesyt","visimdesyt","dev'ynosto"};

    std::vector<int> r = decimal(n);
    int num_letters = 0; 
    for(int i=1;i<r.size();++i){
         int p = r[i];
         if(i==0){
             num_letters += least[p].length();
         }
         else if (i==1){
            num_letters += least[p].length() + dec[p].length();
         }
        else if(i==2){
            if(p==1) num_letters += 3; // sto
            else{
               num_letters += 3;
               num_letters +=least[p].length(); 
            } 
         }
        else{
            num_letters +=least[p].length();
            num_letters += std::string("tysy4a").length(); 
        }
    }
    return num_letters;

}


int main(){

  for(int i=1;i<10000;++i){
       int m = f(i);
       if (m==i) std::cout<<"m="<<i;
  }

}
