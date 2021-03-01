#include <iostream>

//#define N 5 - evil for C++!!!

using namespace std; 

static const size_t N = 5;

int main(){

  int mas[] = {5,12,3,4,7};

  double a;
  cout<<"a=";
  cin>>a;

  int count = 0;
  for(int i=0;i<N;i++){
     if (mas[i]<a) count++;
 }

 cout<<"K="<<count;

}

