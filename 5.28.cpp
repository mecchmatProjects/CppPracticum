#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string str;
    ifstream f;
    ofstream g;
    f.open(R"(C:/Users/sofidoroshenko/Desktop/F.txt)", ios::in);
    g.open(R"(C:/Users/sofidoroshenko/Desktop/G.txt)", ios_base::out);
    while (!f.eof()) {
        f >> str;
        if (stoi(str) >= 0)
            g << str << " ";
    }

    f.close();
    g.close();
}


