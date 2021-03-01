#include <iostream>
#include <cmath>

static const size_t N = 3;// 10;

using namespace std;

int main(){

  double mas[N];

  for(int i=0;i<N;i++){
     cout<<"mas["<<i<<"]=";
     cin>>mas[i];
 }

 double sum = 0.0;
 for(int i=0;i<N;i++){
    if(mas[i]>M_E){
      sum += mas[i];
    }
 }

 cout<<"Sum ="<< sum;

}

