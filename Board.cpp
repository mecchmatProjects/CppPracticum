#include "Board.h"

Board::Board(std::string *name, int size): name(name), size(size) {}

Board::~Board() {
    delete name;
}

void Board::addFigure(Figure *other) {
    figures.push_back(other);
}

int Board::getSize() const {
    return size;
}

std::string *Board::getName() const {
    return name;
}

std::vector<Figure *> Board::getFigures() const {
    return figures;
}
