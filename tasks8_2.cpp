
/*
  На базі класу Точка на площині створіть клас Точка3Д (точка
  в просторі. Реалізуйте методи введення, виведення.
  Реалізуйте методи за допомогою даних класів клас Відрізок,
  що дозволяє працювати з точками розмірностей 2 та 3. 
  введення та виведення, визначення довжини відрізка та
  визначення чи перетинаються два відрізки.
*/
#include <iostream>
#include <cmath>
using namespace std;

typedef double REAL;

class TPoint{
   
   protected:
   REAL x,y;
   size_t dim;

   public:
    TPoint(){ dim=2; }
    TPoint(REAL x_, REAL y_):x(x_),y(y_),dim(2){}

    void setX(REAL x){
       this->x=x;
    }

    void setY(REAL y){
       this->y=y;
    }
    REAL getX(){
       return x;
    }
    REAL getY(){
       return y;
    }

    friend ostream & operator<<(ostream& f, const TPoint & p){
       f<<"("<<p.x<<","<<p.y<<")";
       return f;    
    }

    int input(){
      cout<<"x,y:";
      cin>>x>>y;
   }

   size_t getDim(){
      return dim;
  }

};

class TPoint3D : public TPoint{
    REAL z;
    public:
    TPoint3D(){dim=3;}
    TPoint3D(REAL x_, REAL y_, REAL z_):TPoint(x_,y_),z(z_){ dim=3; }

    void setZ(REAL x){
       this->z=z;
    }
    REAL getZ(){
       return z;
    }

   int input(){
      TPoint::input();
      cout<<"z=";
      cin>>z;
   }

   friend ostream & operator<<(ostream& f, const TPoint3D & p){
       f<<"("<<p.x<<","<<p.y<<","<<p.z<<")";
       return f;    
    }
};


class Segment{
   TPoint a;
   TPoint b;

   public:

   void setA(const TPoint& a){
     this->a = a;
   }
   TPoint getA(){
      return a;
   }
   void setB(const TPoint& b){
     this->b = b;
   }
   TPoint getB(){
      return b;
   }
 
   REAL length(){
      REAL d1 = (a.getX()- b.getX());   
      REAL d2 = (a.getY()- b.getY());
      REAL r =  d1*d1+d2*d2;  
      if(a.getDim()>=3){
         TPoint3D *q1 = static_cast<TPoint3D*> (&a);
         TPoint3D *q2 = static_cast<TPoint3D*> (&b);
         REAL d3 = (q1->getZ()- q2->getZ());   
         r += d3*d3;
      }
      return sqrt(r);
   }

   int input(){
      a.input();
      b.input();
      return 0;
   }

};


int main(){
  TPoint3D p1(1,2,3);
  TPoint3D p2;

  p2.input();
  cout<<p1<<p2;

  Segment s1;
  s1.setA(p1);
  s1.setB(p2);
 
  cout<<s1.length();

}


