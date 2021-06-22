#include <iostream>
#include <cmath>
using namespace std;

class Point
{
private:



 static int count;


public:

 double x;

 double y;


 Point() { this->x = 0; this->y = 0; }

 Point(double x, double y) { this->x = x; this->y = y; }


 void show() { cout << "(" << this->x << ", " << this->y << ")\n"; }
 void input()

 {

  cout << "x, y = ";
  cin >> this->x >> this->y;
  ++count;
 }



 static void shownumber()
 {
  cout << "Number of points: " << count << '\n';
 }

};

const double dist(const Point pt1, const Point pt2)
{



 return sqrt(pow(pt1.x - pt2.x, 2) + pow(pt1.y - pt2.y, 2));



}

int Point::count = 0;
int main()
{

 string s;
 Point ptS, ptC, ptP; 
 double P = 0.0; 
 cout << "Enter 3 points:\n"; 

 ptS.input(); 
 ptP.input(); 
 ptC.input(); 
 
 P += dist(ptS, ptP); 

 cout << "->P = " << P << '\n'; 

 P += dist(ptP, ptC); 

 cout << "->P = " << P << '\n';

 cout << "Want to continue adding points? y/n: ";
 cin >> s; 


 while (s[0] != 'n') 
 {

  ptP.x = ptC.x; 

  ptP.y = ptC.y;

  ptC.input(); 
  
  P += dist(ptC, ptP); 

  cout << "->P = " << P << '\n'; 
  cout << "Want to continue adding points? y/n: "; 
  cin >> s; 



 }



 ptC.shownumber(); 

 P += dist(ptS, ptC); 

 cout << "Perimeter of figure = " << P << '\n'; 



}