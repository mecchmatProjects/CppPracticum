
#include <iostream>
#include <cstdio>
#include <cctype>
using namespace std;

class Point { 
   private:
       static int count; 
       double x; double y; 
   public:
    Point() { this->x = 0; this->y = 0; } 
    Point(double x, double y) { this->x = x; this->y = y; } 
   void show() { cout << "(" << this->x << "," << this->y << ")"<< endl; } 
   int input() { cout << "x, y = "; cin >> this->x >> this->y; 
     count++; 
  } 

   static void shownumber(){
      cout<<"Number of points = "<<count;
   }

 };

int Point::count = 0;

int main(){

   Point p; // p.input();
   string c;
   int k=0;
  do{
     cout<<"Input vertex:";
     p.input();
     k++;

     cout<<"Input another vertex y/n?";
     cin>>c;
     if (tolower(c[0])=='n'){
        break;
     }
  }while(true);

  cout<<k;
  p.shownumber();
}




