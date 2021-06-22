#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    ifstream is("old.txt");
    ofstream out("new.txt");
    
    string str;
    
    while (is >> str)
    {
        out << str << '\n';
        int price;
        is >> price;
        out << price / 1000 << "грн. " << price % 1000 << "коп.\n";
    }
}
