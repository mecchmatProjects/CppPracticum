#include <iostream>
#include <string.h>
#include <chrono>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
using namespace chrono;
time_t dateToTimeT(int month, int day, int year,int month1, int day1, int year1) {//отнимание

 // 5 января 2000 года передается как (1, 5, 2000)
 tm tmp = tm();

 tmp.tm_mday = day;

 tmp.tm_mon = month - 1;

 tmp.tm_year = year - 1900;

tm tmp1 = tm();

 tmp1.tm_mday = day1;

 tmp1.tm_mon = month1 - 1;

 tmp1.tm_year = year1 - 1900;

 return mktime(&tmp)-mktime(&tmp1);

}


time_t dateToTimeT1(int month, int day, int year,int month1, int day1, int year1) {//сравнение
 tm tmp = tm();

 tmp.tm_mday = day;

 tmp.tm_mon = month - 1;

 tmp.tm_year = year - 1900;

tm tmp1 = tm();

 tmp1.tm_mday = day1;

 tmp1.tm_mon = month1 - 1;

 tmp1.tm_year = year1 - 1900;
    if(mktime(&tmp)>mktime(&tmp))return mktime(&tmp);
    else return mktime(&tmp1);

}


time_t Next(int month, int day, int year) {//Next елемент
 tm tmp = tm();

 tmp.tm_mday = day;

 tmp.tm_mon = month - 1;

 tmp.tm_year = year - 1900;

return mktime((&tmp)+86000);
}
class Data{
    int day;
    int month;
    int year;

public:
    Data(int Day = 0, char Month = 0, int Year = 0){
        day = Day;
        month=Month;
        year = Year;
    }

    void Get(){
        cout<<"Day: ";
        cin>>day;
        while(day>31||day==0){
            cout<<"Incorrect"<<endl;
            cout<<"Day: ";
            cin>>day;
        }
        cout<<"Month: ";
        cin>>month;
        cout<<"Year: ";
        cin>>year;
    }

   int inc(int r){
        day=day+r;
        if(day>31){
            day=day-30;
            month+=1;
        }
        return 0;
    }

    int dec(int r){
        day=day-r;
        if(day<=0){
            day=day+30;
            month-=1;
        }
        return 0;
    }

    void print(){
        switch(month){
            case 1:
                cout <<"Day:"<<day<<"\tMonth: "<<month<<"(January)"<<"\tYear:"<<year<<endl;
                break;
                case 2:
                    cout <<"Day:"<<day<<"\tMonth: "<<month<<"(February)"<<"\tYear:"<<year<<endl;
                    break;
                    case 3:
                        cout <<"Day:"<<day<<"\tMonth: "<<month<<"(March)"<<"\tYear:"<<year<<endl;
                        break;
                        case 4:
                            cout <<"Day:"<<day<<"\tMonth: "<<month<<"(April)"<<"\tYear:"<<year<<endl;
                            break;
                            case 5:
                                cout <<"Day:"<<day<<"\tMonth: "<<month<<"(May)"<<"\tYear:"<<year<<endl;
                                break;
                                case 6:
                                    cout <<"Day:"<<day<<"\tMonth: "<<month<<"(June)"<<"\tYear:"<<year<<endl;
                                    break;
                                    case 7:
                                        cout <<"Day:"<<day<<"\tMonth: "<<month<<"(July)"<<"\tYear:"<<year<<endl;
                                        break;
                                        case 8:
                                            cout <<"Day:"<<day<<"\tMonth: "<<month<<"(August)"<<"\tYear:"<<year<<endl;
                                            break;
                                            case 9:
                                                cout <<"Day:"<<day<<"\tMonth: "<<month<<"(September)"<<"\tYear:"<<year<<endl;
                                                break;
                                                case 10:
                                                    cout <<"Day:"<<day<<"\tMonth: "<<month<<"(October)"<<"\tYear:"<<year<<endl;
                                                    break;
                                                    case 11:
                                                        cout <<"Day:"<<day<<"\tMonth: "<<month<<"(November)"<<"\tYear:"<<year<<endl;
                                                        break;
                                                        case 12:
                                                            cout <<"Day:"<<day<<"\tMonth: "<<month<<"(December)"<<"\tYear:"<<year<<endl;;
                                                            break;
                                                            default:
                                                                cout << "Incorrect symbol";
        }
    }
};
typedef unsigned int uint;
const char maxSec = 60;
const char maxMin = 60;
const char maxHr = 24;
class Time{
private:
    uint hour;
    uint minute;
    uint second;
public:
    void Print(){
        cout <<"Hours:"<<hour<<"\tMinutes: "<<minute<<"\tSeconds:"<<second<<endl;
    }
    Time(uint h = 0, uint m = 0, uint s = 0) :
    hour(h), minute(m), second(s){}
    Time(string time = "00:00:00")//Перетворення
    {
        vector<uint> vec;
        istringstream iss(time);
        string str;
        int val;
        while(getline(iss, str, ':')){
            stringstream ss;
            ss << str;
            ss >> val;
            vec.push_back(val);
        }
        hour = vec[0];
        minute = vec[1];
        second = vec[2];
    }
    void setHour(uint h){ hour = h; }
    void setMinute(uint m){ minute = m; }
    void setSecond(uint s){ second = s; }

    uint getHour()const{ return hour; }
    uint getMinute()const{ return minute; }
    uint getSecond()const{ return second; }

    static Time secToTime(uint sec)//кількість заданий одиниць
    {
        uint h = (uint)(sec / maxMin / maxHr);
        uint m = (uint)(sec / maxMin);
        uint s = sec - m * (maxMin);

        return Time(h, m, s);
    }
    static uint TimeToSec(Time & t){
        return (t.getSecond() + t.getMinute() * maxMin + t.getHour() * maxHr * maxMin);
    }
    friend ostream & operator <<(ostream & out, Time & t);//додавання і віднімання
    Time operator -(Time & t){
        uint h = hour - t.getHour() < 0 ? 0 : hour - t.getHour();
        uint m = minute - t.getMinute() < 0 ? 0 : minute - t.getMinute();
        uint s = second - t.getSecond() < 0 ? 0 : second - t.getSecond();
        return Time(h, m, s);
    }

    Time operator -(uint sec){
        Time t(Time::secToTime(sec));
        return *this - t;
    }

    bool operator ==(Time & t) {
        return hour == t.getHour() && minute == t.getMinute() && second == t.getSecond();
    }
    bool operator !=(Time & t){
        return hour != t.getHour() && minute != t.getMinute() && second != t.getSecond();
    }
};

int main(){
    using namespace chrono;
    auto period = system_clock::period();
    double period_s = (double) period.num / period.den;
    int r;
    int zn;
    Data d;
    d.Get();
    d.print();
    cout<<"\n"<<"Put: 0 - if plus days; 1 - if minus days"<<endl;
    cin>>r;
    cout<<"\nHow many days: ";
    cin>>zn;
    if(r == 0){
        d.inc(zn);
    }
    else
        d.dec(zn);
    dateToTimeT(5,2,1999,1,5,2001);
    d.print();

    Time time(10, 15, 22);
    int a,b,c,h1;
    cout<<"Days - ";
    cin>>h1;
    cout<<"Hours - ";
    cin>>a;
    cout<<"Minutes - ";
    cin>>b;
    cout<<"Seconds - ";
    cin>>c;
    Time timij(a,b,c);
    timij.Print();
    Time time1("11:16:23");
    Time time2(Time::secToTime(70));
    Time time3((time1 - time));
    cout<<"After getting"<<endl;
    Time time4((timij - 120));
    time4.Print();

    system("pause");
}
