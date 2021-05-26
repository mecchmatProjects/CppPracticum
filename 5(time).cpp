
#include <iostream>
using namespace std;

class Time {
private:
    int second1, minute1, hour1, day1;
    int second2, minute2, hour2, day2;
public:
    void set() {
        cout << "1. day:" << "hour:" << "minute:" << "second";
        cin >> day1 >> hour1 >> minute1 >> second1;
        cout << "2. day:" << "hour:" << "minute:" << "second";
        cin >> day2 >> hour2 >> minute2 >> second2;
    }
    void Check(){
        while (hour1 >24||minute1>60||second1>60){
            cout << "Incorrect form, try one more time" << endl;
            cin >> day1 >> hour1 >> minute1 >> second1;
        }
        while (hour2 >24||minute2>60||second2>60){
            cout << "Incorrect form, try one more time" << endl;
            cout << "2. day:" << "hour:" << "minute:" << "second";
            cin >> day2 >> hour2 >> minute2 >> second2;
        }
    }

    void show() {
        cout << "Date1: " << day1 << "   " << hour1 << ":" << minute1 << ":" << second1 << endl;
        cout << "Date2: " << day2 << "   " << hour2 << ":" << minute2 << ":" << second2 << endl;

    };

    void AddTimeToTime() {
        int d1 = day1;
        int h1 = hour1;
        int m1 = minute1;
        int s1 = second1;
        int d2 = day2;
        int h2 = hour2;
        int m2 = minute2;
        int s2 = second2;


        for (int i = 0; i < s2; i++) {
            if (++s1 > 60) {
                s1 = 1;
                m1++;
            }

        }
        for (int i = 0; i < m2; i++) {
            if (++m1 > 60) {
                m1 = 0;
                h1++;
            }
        }
        for (int i = 0; i < h2; i++) {
            if (++h1 > 24) {
                h1 = 0;
                d1++;
            }
        }
        for (int i = 0; i < d2; i++) {
            d1++;
        }
        cout << "plus Time " << d1 << " -- " << h1 << ":" << m1 << ":" << s1 << endl;
    }


    void AddTimeToDate(){
        int d1 = day1;

        int year, month, day;
        cout << "Year/" << "Month/" << "Day";
        cin >> year >> month >> day;
        cout << year << "/" << month << "/" << day << endl;

        for (int i = 0; i < d1; i++) {
            if (month == 4 || month == 6 || month == 9 || month == 11) {
                if (++day > 30) {
                    day = 1;
                    month++;
                }
            }
            if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
                if (++day > 31) {
                    day = 1;
                    month++;
                }
            }

            if (month > 12) {
                month = 1;
                year++;
            }
        };
        cout << "date plus time =  " << year << "/" << month << "/" << day << "  --  " << hour1 << ":" << minute1<< ":"<< second1 << endl;
    };
};

int main() {
    setlocale(0, "");
    Time n1;
    n1.set();
    n1.Check();
    n1.show();
    n1.AddTimeToTime();
    n1.AddTimeToDate();
    return 0;
}