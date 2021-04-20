
#include <iostream>
#include <cmath>
using namespace std;

class Point{
   double x,y;
 
   public:
   static int counter;
   void input(){
      cout<<"x,y";
      cin>>x>>y;
      counter++;
   }
  
   static int getCount(){
       return counter;
   }

   friend double dist(Point& p1, Point& p2) ; 
};


double dist(Point& p1, Point& p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}


int Point::counter = 0;

int main(){
   string answer;
   int m=0;
   Point p_prev;
   Point p_first;
   double d1=0;
   do{
    cout<<"Continue enter points?y/n";
    cin>>answer;
    if(answer.length()>=1 && tolower(answer[0])=='y'){   
      Point p; 
      p.input();
      m++;
      
      if(Point::getCount()>1){
        d1 += dist(p, p_prev);
      }
      else{
         p_first = p;
      }   
      p_prev = p;
    }
    else{
      break;
    }
  } while(true);

  Point z;
  cout<<Point::getCount()<<z.counter; 
  d1 += dist(p_first,p_prev);
  cout<<"Preimeter"<<d1;
}


