#include <iostream>
#include<fstream>
#include <string>
#include <cstring>

using namespace std;

void blankline()
{
    ifstream file("C:/Users/okot/Desktop/Uni/untitled4/out.txt");
    string str;
    int count=0;
    while (getline(file, str))
    {
        if(str.size()==0)
            count++;
    }
    cout<< count;
}
void biggest_line(){
    ifstream file("C:/Users/okot/Desktop/Uni/untitled4/out.txt");
    string str;
    int maximum=0;
    while (getline(file, str))
    {
        if(str.size() > maximum){
            maximum = str.size();
    }
    cout<< maximum;
}
};
int main() {
    blankline();
    biggest_line();
    return 0;
};