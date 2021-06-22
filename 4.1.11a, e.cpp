#include <iostream>
#include <fstream>
using namespace std;

#pragma pack(push, 1)

struct Toy {
    string toy;
    int cost;
    int from;
    int to;
};

#pragma pack(pop)

int main()
{
    Toy first = {"ball", 100, 2, 5 };
    Toy second = {"doll", 200, 5, 7 };
    Toy third = {"constructor", 300, 3, 6 };
    string fileName = "toys.bin"; // Binary file name

    ofstream outputFile;
    outputFile.open(fileName.c_str(), ios::binary);

    ///// Write Binary File ////
    if(outputFile.is_open())
    {
        outputFile.write(reinterpret_cast<char*>(&first), sizeof(Toy));
        outputFile.write(reinterpret_cast<char*>(&second), sizeof(Toy));
        outputFile.write(reinterpret_cast<char*>(&third), sizeof(Toy));
        outputFile.close();
    }
    else
    {
        cout << "Could not create file " + fileName + "\n";
    }

    ///// Read Binary File ////

    Toy smth[3];
    ifstream inputFile;
    inputFile.open(fileName.c_str(), ios::binary);
    if(inputFile.is_open())
    {
        for (auto & i : smth)
            inputFile.read(reinterpret_cast<char*>(&i), sizeof(Toy));
        inputFile.close();
    }
    else
    {
        cout << "Could not read file " + fileName;
    }

    int money, age;
    cout << "money = ";
    cin >> money;
    cout << "age = ";
    cin >> age;


    string file = "toy_found.bin"; // Binary file name
    ofstream File;
    File.open(file.c_str(), ios::binary);
    if(File.is_open())
    {
        for (int i=0; i<3; i++){
            if (smth[i].cost <= money & smth[i].from <= age & smth[i].from >= age){
                cout << smth[i].toy << ", " << smth[i].cost << ", " << smth[i].from << ", " << smth[i].to << endl;
                Toy add = {smth[i].toy, smth[i].cost, smth[i].from, smth[i].to };
                File.write(reinterpret_cast<char*>(&add), sizeof(Toy));
            }else if (smth[i].cost == money & smth[i].from == 5 & smth[i].from == 10 & smth[i].toy == "constructor") {
                cout << smth[i].toy << ", " << smth[i].cost << ", " << smth[i].from << ", " << smth[i].to << endl;
                Toy add = {smth[i].toy, smth[i].cost, smth[i].from, smth[i].to };
            }
            else{
                File << "no such toy";
                }
            }
        File.write(reinterpret_cast<char*>(&first), sizeof(Toy));

        outputFile.close();
    }else
    {
        cout << "Could not create file " + fileName + "\n";
    }
    return 0;
}