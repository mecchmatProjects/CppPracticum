#include <iostream>
using namespace std;

class Date {
private:
    int year, month, day;

public:

    void set(){
        cout << "Year:";
        cin >> year;
        cout << "Month:";
        cin >> month;
        cout << "day:";
        cin >> day;
    }

    void show(){
        cout << "Date: " << year << "/" << month << "/"<< day << endl;

    };

    void getPrevDate(){
        //if there is first day of month
        if(day==1){
            //months which have 30 days in previous month
            if(month==4|| month==6|| month==9|| month==11){
                day=31;
                month = month -1;
            }
                //for MARCH, to define february last day
            else if(month==3){
                if(year%4==0)
                    day=29;
                else
                    day=28;
                month = month -1;
            }
                //for January, to define December last day
            else if(month==1){
                day=31;
                month = 12;
                year = year - 1 ;
            }
                //for Feb, to define January last day
            else if(month==2){
                day=31;
                month = month -1;
            }
                //for other months
            else{
                day=30;
                month = month -1;
            }
        }
            //other days of month
        else{
            day = day-1;
        }
        cout<<endl<<"Previous date : "<<year<<"/"<<month<<"/"<<day<<endl;

    }
    void getNextDate(){
        if(day==30){
            //months which have 31 days in month
            if(month==1|| month==3|| month==5|| month==7 || month==8|| month==10){
                day=1;
                month = month +1;
            }
            if(month==12){
                day=1;
                month = 1;
                year = year + 1 ;
            }
            else{
                day = day+2;
            }
        }

        if (day==28){
            if(month==2){
                day=1;
                month = month +1;
            }
        }
        if (day==27){
            if(month==2){
                day=1;
                month = month +1;
            }
        }

        if(day==29){
            if(month==4|| month==6|| month==9|| month==11){
                day=1;
                month = month +1;
            }
            else{
                day = day+2;
            }
        }
        else{
            day = day+2;
        }
        cout<<endl<<"Next date : "<<year<<"/"<<month<<"/"<<day<<endl;
    }

};

int main() {
    setlocale(0, "");
    Date n1;
    n1.set();
    n1.show();
    n1.getPrevDate();
    n1.getNextDate();


    system("pause");
    return 0;
}