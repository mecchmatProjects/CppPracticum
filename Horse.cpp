#include "Horse.h"
using namespace std;

Horse::Horse(Board *board, int x, int y): Figure(new string("Horse"), new string("Chess"), board, x, y) {}

std::vector<std::pair<int, int>> Horse::goTo() {
    vector<pair<int, int>> tmp;
    if (check_position(getPosition().first + 2, getPosition().second + 1)) {
        tmp.emplace_back(getPosition().first + 2, getPosition().second + 1);
    }

    if (check_position(getPosition().first + 2, getPosition().second - 1)) {
        tmp.emplace_back(getPosition().first + 2, getPosition().second - 1);
    }

    if (check_position(getPosition().first - 2, getPosition().second + 1)) {
        tmp.emplace_back(getPosition().first - 2, getPosition().second + 1);
    }

    if (check_position(getPosition().first - 2, getPosition().second - 1)) {
        tmp.emplace_back(getPosition().first - 2, getPosition().second - 1);
    }

    if (check_position(getPosition().first + 1, getPosition().second + 1)) {
        tmp.emplace_back(getPosition().first + 1, getPosition().second + 2);
    }

    if (check_position(getPosition().first + 1, getPosition().second - 2)) {
        tmp.emplace_back(getPosition().first + 1, getPosition().second - 2);
    }

    if (check_position(getPosition().first - 1, getPosition().second + 2)) {
        tmp.emplace_back(getPosition().first - 1, getPosition().second + 2);
    }

    if (check_position(getPosition().first - 1, getPosition().second - 2)) {
        tmp.emplace_back(getPosition().first - 1, getPosition().second - 2);
    }

    return tmp;
}
