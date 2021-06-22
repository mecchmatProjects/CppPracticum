#include <iostream>
#include <fstream>
#include "Book/Book.h"
#include "Catalog/Catalog.h"
using namespace std;

int main() {
    Catalog cat;
    vector<Book*> res;
    ifstream in;
    string tmpName, tmpAuthor;
    int N;

    in.open(R"(D:\C++\150\catalog.txt)");
    in >> N;

    for (int i = 0; i < N; i++) {
        in >> tmpName >> tmpAuthor;
        cat.addBook(new Book(new string(tmpName), new string(tmpAuthor)));
    }

    res = cat.findAuthor(new string("cc"));

    for (int i = 0; i < res.size(); i++) {
        cout << *res[i]->getName() << ' ' << *res[i]->getAuthor() << endl;
    }

    in.close();

    return 0;
}