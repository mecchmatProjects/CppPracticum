#ifndef INC_9_BOARD_H
#define INC_9_BOARD_H

class Figure;

#include <iostream>
#include <vector>
#include "../Figure/Figure.h"

class Board {
private:
    int size;
    std::string* name;
    std::vector<Figure*> figures;
public:
    Board(std::string* name, int size);
    ~Board();

    void addFigure(Figure* other);

    int getSize() const;
    std::string* getName() const;
    std::vector<Figure*> getFigures() const;
};


#endif //INC_9_BOARD_H
