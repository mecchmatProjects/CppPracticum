
#include <iostream>
#include <set>

using namespace std;


int input(set<int> & s){
    int x; 
    int k=0;
    do{
       cin>>x;
       if(x==0) break; 
        // if x in S
       if(s.find(x)!= s.end()){
         k++;
       } 
       s.insert(x);
    } while(true);

    return k;
}

int output(const set<int> & s){
   cout<<"s="; 
   for(set<int>::const_iterator it= s.begin(); it!=s.end();++it){
      cout<<*it<<",";
   }
   cout<<endl;
}


int pair_sum(const set<int> & s){
    
    int sum = 0;
    int tmp = 0;  
    int k =0; 

    if(s.size()<=1) return *s.begin();
  
    set<int> s2;
    for(set<int>::iterator it= s.begin(); it!=s.end();++it){
        if(k%2==0){
           tmp = *it;
        } 
        else{
           tmp += *it;
           s2.insert(tmp);
           tmp = 0; 
        }
        k++;
        //cout<<"k="<<k<<*it;
    }

    if(k%2==1) {s2.insert(tmp);}

    //output(s2);
    return pair_sum(s2); 

}


int main(){

  set<int> s1;
  input(s1);
  output(s1);
  int res = pair_sum(s1);
  cout<<res;
}
