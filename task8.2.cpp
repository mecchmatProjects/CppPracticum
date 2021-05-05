

#include <iostream>
#include <cmath>

using namespace std;

class Point {
    int dim;
  protected:
    double x,y;

  public:

  Point(){dim=2;}
  Point(double x_,double y_):x(x_),y(y_){dim=2;}

  int input(){
   cout<<"x,y:";
   cin>>x>>y;
  }

  void show(){
   cout<<"("<<x<<","<<y<<")\n";
  }

  double getX() { return x;}
  double getY() { return y;}
  int getdim(){ return dim;}
};


class Point3D: public Point{
  int dim;
  double z;
 public:
  
  Point3D(){dim=3;}
  Point3D(double x_,double y_,double z_):Point(x,y),z(z_){dim=3;}

  int input(){
   cout<<"x,y,z:";
   cin>>x>>y>>z;
  }

  void show(){
   cout<<"("<<x<<","<<y<<","<<z<<")\n";
  }

  double getZ() { return z;}


};


class Segment{
  Point p1,p2;
  public:
  Segment(){}
  Segment(Point x, Point y) { p1=x;p2=y;}

  double length(){
 
     double r = (p1.getX()-p2.getX())*(p1.getX()-p2.getX()) + (p1.getY()-p2.getY())*(p1.getY()-p2.getY());
     if(p1.getdim()!=2){
        Point3D* q1 = (Point3D*)&p1 ;
        Point3D* q2 =(Point3D*)&p2 ;
        r+= (q1->getZ()-q2->getZ())*(q1->getZ()-q2->getZ());   
     }
     return sqrt(r);
  }
  
};

class Segment3D{
  Point3D p1,p2;
  public:
  Segment3D(){}
  Segment3D(Point3D x, Point3D y) { p1=x;p2=y;}

  double length(){
     
     double r = (p1.getX()-p2.getX())*(p1.getX()-p2.getX()) + (p1.getY()-p2.getY())*(p1.getY()-p2.getY());
     double r1 = r + (p1.getZ()-p2.getZ())*(p1.getZ()-p2.getZ());   
     return sqrt(r1);
  }
  
};



int main(){
  Point p1,p2;

  p1.input();
  p2.input();

  Segment s(p1,p2);

  cout<<s.length()<<endl;


 Point3D p3,p4;
  p3.input();
  p4.input();

  Segment3D s2(p3,p4);

  cout<<s2.length();
}



