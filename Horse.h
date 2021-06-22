#ifndef INC_9_HORSE_H
#define INC_9_HORSE_H

#include "../Figure/Figure.h"

class Horse: public Figure {
public:
    Horse(Board* board, int x = 0, int y = 0);

    std::vector<std::pair<int, int>> goTo();
};


#endif //INC_9_HORSE_H
