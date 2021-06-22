#ifndef INC_150_CATALOG_H
#define INC_150_CATALOG_H

#include "../Book/Book.h"
#include "vector"

class Catalog {
private:
    std::vector<Book*> catalog;
public:
    Catalog();

    void addBook(Book* other);

    std::vector<Book*> findName(std::string* name) const;
    std::vector<Book*> findAuthor(std::string* author) const;

    std::vector<Book*> getCatalog() const;
};


#endif //INC_150_CATALOG_H
