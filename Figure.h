#ifndef INC_9_FIGURE_H
#define INC_9_FIGURE_H

class Board;

#include <utility>
#include "../Board/Board.h"

class Figure {
private:
    Board* board;
    std::string* name;
    std::string* gameName;
    std::pair<int, int> position;
public:
    Figure(std::string* name, std::string*gameName, Board* board, int x = 0, int y = 0);
    ~Figure();

    int check_position(int x, int y);

    virtual std::vector<std::pair<int, int>> goTo() = 0;

    std::pair<int, int> getPosition();
};


#endif //INC_9_FIGURE_H
