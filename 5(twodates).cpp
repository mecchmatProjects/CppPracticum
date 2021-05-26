#include <iostream>
using namespace std;

class Date {
private:
    int year1, month1, day1;
    int year2, month2, day2;


public:

    void set() {
        cout << "1. Year/" << "Month/" << "day/";
        cin >> year1 >> month1 >> day1;
        cout << "2. Year/" << "Month/" << "day/";
        cin >> year2 >> month2 >> day2;
    }

    void show() {
        cout << "Date1: " << year1 << "/" << month1 << "/" << day1 << endl;
        cout << "Date2: " << year2 << "/" << month2 << "/" << day2 << endl;

    };

    void compare() {
        if (year1 != year2) {
            if (year1 > year2) {
                cout << "Date1 later then Date2" << endl;
            } else if (year1 < year2) {
                cout << "Date2 later then Date1" << endl;
            }
        }
        if (year1 == year2) {
            if (month1 > month2) {
                cout << "Date1 later then Date2" << endl;
            } else if (month2 > month1) {
                cout << "Date2 later then Date1" << endl;
            }
        } else if (year1 == year2 || month2 == month1) {
            if (day1 > day2) {
                cout << "Date1 later then Date2" << endl;
            }
            if (day1 < day2) {
                cout << "Date2 later then Date1" << endl;
            }
        }
        if (year1 == year2 || month2 == month1 || day1 == day2) {
            cout << "The same" << endl;
        }
    };

    void dayscounter() {
        int  e, d, a, b, c, res;
        a = year1 - year2;
        b = a / 4;
        c = a - b;
        d = b * 366 + c * 365;
        d -= (year1 % 4) ? 1 : 0;

        for (e = 1; e < month2; e++) {
            if (e == 2) d -= (year1 % 4) ? 28 : 29;
            else if (e == 4 || e == 6 || e == 9 || e == 11) d -= 30;
            else d -= 31;
        };
        if (month2 != 12 && a == 1) res = day2 + d;
        else res = d - day2;
        cout << "between" << res << "days" << endl;

    }
    void PlusDays(){
        int addDays = 12;
        int y=year1;
        int m=month1;
        int d=day1;

    for(int i = 0; i < addDays;i++) {
        if (m == 4 || m == 6 || m == 9 || m == 11) {
            if (++d > 30) {
                d = 1;
                m++;
            }
        }
        if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10) {
            if (++d > 31) {
                d = 1;
                m++;
            }
        }

        if (m > 12) {
            m = 1;
            y++;
        }
    };
    cout << "plus 12 days " << y << "/" << m << "/" << d  << endl;
    }
    void MinusDays(){
        int y=year1;
        int m=month1;
        int d=day1;

        int conDays = 12;

        for(int i = 0; i < conDays;i++) {
            if (m == 2 || m == 4 || m == 6 || m == 8 || m == 9 || m == 11) {
                if (--d < 1) {
                    d= 31;
                    m--;
                }
            }
            else if (m == 3 || y % 4 == 0){
                if (--d<1){
                    d = 29;
                    m--;
                }
            }
            else if (m == 3 || y % 4 != 0){
                if (--d<1){
                    d = 28;
                    m--;
                }
            }
            else if ( m == 5 || m == 7 || m == 10 || m == 12) {
                if (--d <1) {
                    d = 30 ;
                    m--;
                }
            }

            if (m < 1) {
                m = 12;
                y--;
            }
        };
        cout << "minus days " << y << "/" << m<< "/" << d  << endl;
    }
    void PlusDats(){
        int y1=year1;
        int m1=month1;
        int d1=day1;
        int y2=year2;
        int m2=month2;
        int d2=day2;
        int newy, newd, newm;




    }

};


int main() {
    setlocale(0, "");
    Date n1;
    n1.set();
    n1.show();
    n1.compare();
    n1.dayscounter();
    n1.PlusDays();
    n1.MinusDays();
    n1.getPrevDate();
    n1.getNextDate();


    system("pause");
    return 0;
}