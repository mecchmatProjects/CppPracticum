#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    cout << "Enter number:\n";
    std::string snum;
    cin >> snum;
    double num = atof(snum.c_str());
    cout << "\na). Result is: \n\n";
    cout << num << "  " << num << "  " << num << endl;
    cout << num << "  " << num << endl;
    cout << num << "  " << num << "  " << num << endl;
    cout << "\nb). Result is: \n\n";
    cout << "  " << num << "----------" << num << endl;
    cout << "|    " << num << "    |"<<endl;
    cout << "  " << num << "----------" << num << endl;
    return 0;
}