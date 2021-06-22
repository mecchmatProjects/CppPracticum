#include <iostream>
#include <utility>
#include <vector>
#include "Board/Board.h"
#include "Horse/Horse.h"
using namespace std;

int main() {
    Board chess(new string("Chess"), 8);

    Horse* h = new Horse(&chess, 0, 5);

    vector<pair<int, int>> res = h->goTo();

    for (int i = 0; i < res.size(); i++) {
        cout << res[i].first << ' ' << res[i].second << endl;
    }

    return 0;
}
