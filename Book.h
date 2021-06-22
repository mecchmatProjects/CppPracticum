#ifndef INC_150_BOOK_H
#define INC_150_BOOK_H

#include <iostream>

class Book {
private:
    std::string* name;
    std::string* author;
public:
    Book(std::string* name, std::string* author);
    ~Book();

    std::string* getName() const;
    std::string* getAuthor() const;
};


#endif //INC_150_BOOK_H
