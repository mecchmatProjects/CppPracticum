#include <iostream>
#include <fstream>

using namespace std;

#pragma pack(push, 1)

struct Component {
    int first;
    int second;
};

#pragma pack(pop)

int main() {
    Component first = {2, 2};
    Component second = {3, 1};
    Component third = {5, 1};
    string fileName = "comp.bin"; // Binary file name

    ofstream outputFile;
    outputFile.open(fileName.c_str(), ios::binary);

    ///// Write Binary File ////
    if (outputFile.is_open()) {
        outputFile.write(reinterpret_cast<char *>(&first), sizeof(Component));
        outputFile.write(reinterpret_cast<char *>(&second), sizeof(Component));
        outputFile.write(reinterpret_cast<char *>(&third), sizeof(Component));
        outputFile.close();
    } else {
        cout << "Could not create file " + fileName + "\n";
    }


    ///// Read Binary File ////
    Component smth[3];
    ifstream inputFile;
    inputFile.open(fileName.c_str(), ios::binary);
    if (inputFile.is_open()) {
        for (auto &i : smth)
            inputFile.read(reinterpret_cast<char *>(&i), sizeof(Component));
        inputFile.close();
    } else {
        cout << "Could not read file " + fileName;
    }
    int minimum = smth[1].first;
    int maximum = smth[1].second;
    {
        for (int i = 0; i < 3; i++) {
            if (smth[i].first < minimum){
                minimum = smth[i].first;
            }
            else if(smth[i].second > maximum){
                maximum = smth[i].second;
            }
        }
    }
    cout <<maximum+minimum;
    return 0;
} 
