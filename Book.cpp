#include "Book.h"

Book::Book(std::string *name, std::string *author): name(name), author(author) {}

Book::~Book() {
    delete name;
    delete author;
}

std::string *Book::getName() const {
    return name;
}

std::string *Book::getAuthor() const {
    return author;
}
