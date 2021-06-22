#include "Figure.h"

Figure::Figure(std::string *name, std::string *gameName, Board *board, int x, int y): name(name), gameName(gameName), board(board) {
    if (check_position(x, y)) {
        position = std::make_pair(x, y);
    }
}

Figure::~Figure() {
    delete name;
    delete gameName;
}

int Figure::check_position(int x, int y) {
    if (x >= 0 && y >= 0 && x < board->getSize() && y < board->getSize()) {
        return 1;
    }
    return 0;
}

std::pair<int, int> Figure::getPosition() {
    return std::make_pair(position.first, position.second);
}
