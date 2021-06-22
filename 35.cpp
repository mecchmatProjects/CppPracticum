#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string tmp;
    ifstream F;
    ofstream H, G;
    int N;

    F.open(R"(D:\C++\150\F.txt)");
    H.open(R"(D:\C++\150\H.txt)");
    G.open(R"(D:\C++\150\G.txt)");

    F >> N;
    getline(F, tmp);              //после считывания числа остается символ перехода строки; так мы его убираем

    for (int i = 0; i < N; i++) {
        getline(F, tmp);
        if (tmp.length() % 2 == 0) {
            G << tmp << endl;
        } else {
            H << tmp << endl;
        }
    }

    F.close();
    H.close();
    G.close();

    return 0;
}