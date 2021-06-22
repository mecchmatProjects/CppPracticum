#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;

class Point{
private:
    double a;
    double b;

public:
    Point():a(0),b(0){}
    Point(double x,double y){
        this->Set_first_coordinate(x);
        this->Set_second_coordinate(y);
    }
    Point& Set_first_coordinate(double x){
        this->a=x;
        return *this;
    }
    Point& Set_second_coordinate(double y){
        this->b=y;
        return *this;
    }
    double Get_first_coordinate(){
        return a;
    }
    double Get_second_coordinate(){
        return b;
    }
    void Print(){
        cout<<"("<<this->Get_first_coordinate()<<" , "<<this->Get_second_coordinate()<<")";
    }

};

double dist(Point& x,Point& y){
    return sqrt(pow(x.Get_first_coordinate()-y.Get_first_coordinate(),2)+pow(x.Get_second_coordinate()-y.Get_second_coordinate(),2));
}

int main(){
    string path;
    cout<<"Введіть шлях до файлу:"<<endl;
    cin>>path;

    ifstream text_file (path);
    vector<Point> points;

    while(text_file.is_open()){
        double temp1,temp2;
        text_file.ignore(1);
        text_file >> temp1;
        text_file.ignore(1);
        text_file>> temp2;
        text_file.ignore(1);
        points.push_back({temp1,temp2});
    }


    vector<vector<Point>> vectors;
    vector<double> distances;
    for(int i=0;i<points.size();i++){
        for(int j=i+1;j<points.size();j++){
            vectors.push_back({points[i],points[j]});
            distances.push_back(dist(points[i],points[j]));
        }
    }


    return 0;
}