#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)

struct Polinom {
    int coef;
    int deg;
    int num;
};

#pragma pack(pop)

int main()
{
    Polinom first = {2, 2, 1};
    Polinom second = {3, 1, 2};
    Polinom third = {5, 1, 1};
    string fileName = "polinom.bin"; // Binary file name

    ofstream outputFile;
    outputFile.open(fileName.c_str(), ios::binary);

    ///// Write Binary File ////
    if(outputFile.is_open())
    {
        outputFile.write(reinterpret_cast<char*>(&first), sizeof(Polinom));
        outputFile.write(reinterpret_cast<char*>(&second), sizeof(Polinom));
        outputFile.write(reinterpret_cast<char*>(&third), sizeof(Polinom));
        outputFile.close();
    }
    else
    {
        cout << "Could not create file " + fileName + "\n";
    }

    int coef, deg, num;

    cout << "coef = ";
    cin >> coef;
    cout << "deg = ";
    cin >> deg;
    cout << "num = ";
    cin >> num;

    Polinom inp = {coef, deg, num};

    outputFile.open(fileName.c_str(), ios::binary);

    ///// Write Binary File by input////
    if(outputFile.is_open())
    {
        outputFile.write(reinterpret_cast<char*>(&inp), sizeof(Polinom));
        outputFile.close();
    }
    else
    {
        cout << "Could not create file " + fileName + "\n";
    }


    ///// Read Binary File ////

    Polinom someoneElse = {};
    ifstream inputFile;
    inputFile.open(fileName.c_str(), ios::binary);
    if(inputFile.is_open())
    {
        inputFile.read(reinterpret_cast<char*>(&someoneElse), sizeof(Polinom));
        cout << someoneElse.coef << ", " << someoneElse.deg << ", " << someoneElse.num << endl;
        inputFile.close();
    }
    else
    {
        cout << "Could not read file " + fileName;
    }
    return 0;
}
