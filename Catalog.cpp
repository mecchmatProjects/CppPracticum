#include "Catalog.h"
using namespace std;

Catalog::Catalog() {
    catalog = vector<Book*>();
}

void Catalog::addBook(Book *other) {
    catalog.push_back(other);
}

vector<Book *> Catalog::findName(string *name) const {
    vector<Book*> res;

    for (int i = 0; i < catalog.size(); i++) {
        if (*catalog[i]->getName() == *name) {
            res.push_back(catalog[i]);
        }
    }

    return res;
}

vector<Book *> Catalog::findAuthor(string *author) const {
    vector<Book*> res;

    for (int i = 0; i < catalog.size(); i++) {
        if (*catalog[i]->getAuthor() == *author) {
            res.push_back(catalog[i]);
        }
    }

    return res;
}

std::vector<Book *> Catalog::getCatalog() const {
    return catalog;
}
