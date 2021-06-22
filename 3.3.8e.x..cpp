#include <iostream>
#include <list>
#include <cstdlib>
#include <iterator>
using namespace std;

int main() {
    list<list<int>> l;
    list<int> tmp;
    int N, M, m, k;

    cin >> N >> M >> m >> k;

    for (int i = 0; i < N; i++) {
        tmp.clear();
        for (int j = 0; j < M; j++) {
            tmp.push_back(rand()%10 + 1);
        }
        l.push_back(tmp);
    }

    for (auto it = l.begin(); it != l.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << ' ';
        }
        cout << endl;
    }



    cout << "**************" << endl;



    //e
    for (auto it = l.begin(); it != l.end(); it++) {
        it->push_front(rand()%10 + 1);
    }

    for (auto it = l.begin(); it != l.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << ' ';
        }
        cout << endl;
    }



    cout << "**************" << endl;



    //x
    for (auto it = l.begin(); it != l.end(); it++) {
        auto it2 = it->begin();
        for (int i = 0; i < m; i++, it2++);
        for (int i = 0; i < k; i++) {
            it->insert(it2, rand()%10 + 1);
        }
    }

    for (auto it = l.begin(); it != l.end(); it++) {
        for (auto it2 = it->begin(); it2 != it->end(); it2++) {
            cout << *it2 << ' ';
        }
        cout << endl;
    }

    return 0;
}

