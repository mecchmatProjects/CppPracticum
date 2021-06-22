#include <iostream>
#include <string.h>
#include <cstdlib>
#include <iomanip>
#include <cstdlib>
#include <fstream>
using namespace std;

class String
{
public:
    char *str;
    String();

    void operator= (String &obj2);
    void operator+ (String &obj2);
    void operator<= (String &obj2);
    void operator>= (String &obj2);
    void operator== (String &obj2);
    void operator!= (String &obj2);

    friend ostream &operator<<(ostream &stream, String obj);
    friend istream &operator>>(istream &stream, String obj);

};

String::String()
{
    str=new char[255];
}


void String::operator=(String &obj2){
    strcpy(str,obj2.str);
}

void String::operator+(String &obj2){
    strcat(str,obj2.str);
}

void String::operator<=(String &obj2){
    int t = atoi(str);
    int k = atoi(obj2.str);
    if (t<=k){
        cout<<"True 1 <= 2"<<endl;
    }
    else
        cout<<"False"<<endl;
}

void String::operator>=(String &obj2){
    int t = atoi(str);
    int k = atoi(obj2.str);
    if (t>=k){
        cout<<"True 1 >= 2"<<endl;
    }
    else
        cout<<"False"<<endl;
}

void String::operator==(String &obj2){
    if( strcmp(str,obj2.str)){
        cout<<"Not equal !"<<endl;
        cout<<str;
        cout<<obj2.str;
    }
    else
        cout<<"Equal !"<<endl;
}

void String::operator!=(String &obj2){
    strcmp(str,obj2.str);
    if( !strcmp(str,obj2.str)){
        cout<<"Equal!"<<endl;
    }
    else
        cout<<"Not equal!"<<endl;
}


ostream &operator<<(ostream &stream, String obj)
{
    stream<<obj.str;
    return stream;
}


istream &operator>>(istream &stream, String obj)
{
    stream>>obj.str;
    return stream;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    String obj1, obj2;
    int deistv;
    cout<<"Input string"<<"\n"<<"-> ";
    cin>>obj1;
    cout<<"\nYour string"<<"\n->";
    cout<<obj1;
    cout<<"Input second string"<<"\n"<<"-> ";
    cin>>obj2;
    cout<<"\nYour string"<<"\n->";
    cout<<obj2;

    while (1){
        cout << "\n"<<"Choose action:\n";
        cout << "1. Adding"<<endl;
        cout << "2. (+)"<<endl;
        cout << "3. (==)"<<endl;
        cout << "4. (!=)"<<endl;
        cout << "5. <="<<endl;
        cout << "6. >="<<endl;
        cout << "7. end"<<endl;
        cout<<"->";
        cin>>deistv;
        if (deistv==1){
            obj2=obj1;
            cout<<"second object contains string: ";
            cout<<obj2;
        }

        if (deistv==2){
            obj2+obj1;
            cout<<"second object contains string: ";
            cout<<obj2;
        }

        if (deistv==3){
            obj2==obj1; }

        if (deistv==4){
            obj2!=obj1;

        }

        if (deistv==5){
            obj1<=obj2;

        }

        if (deistv==6){
            obj1>=obj2;

        }

        if (deistv==7){
            system("PAUSE");
            return 0;}
    }
}
