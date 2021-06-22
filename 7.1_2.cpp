#include<iostream>
#include<cmath>

using namespace std;

class Point{
    double x;
    double y;
    static int counter;
public:
    void input(){
        cout << "x,y =";
        cin >> x >> y;
        counter++;
    }
    double dist(Point p){
        return sqrt(pow(this->x - p.x,2) + pow(this->y - p.y,2));
    }
    static int getCounter(){
        return counter;
    }
};

int Point::counter=0;

int main() {
    string answer;
    Point prev;
    Point first;
    double perimeter = 0;
    do{
        cout << "y/n?";
        cin >> answer;
        if(answer.length() >=1 && tolower(answer[0]) == 'y'){
            Point p;
            p.input();
            if (p.getCounter() == 1) {
                first = p;
            } else{
                perimeter += p.dist(prev);
            }
            prev = p;
        } else{
            break;
        }
    } while (true);
    perimeter += first.dist(prev);
    cout << Point::getCounter() << endl;
    cout << perimeter;
}


