#include <iostream>
using namespace std;

int find_in(string str, string find) {
    int count = 0,
        str_size = str.size(),
        find_size = find.size();
    bool check;

    for (int i = 0; i < str_size - find_size + 1; i++) {
        if (str[i] == find[0]) {
            check = true;
            for(int j = 1; j < find_size && check; j++) {
                if (str[i+j] != find[j]) {
                    check = false;
                }
            }
            if (check) {
                count += 1;
            }
        }
    }

    return count;
}

int main() {
    string str, find;
    int count = 0;

    cin >> str >> find;

    count = find_in(str, find);

    cout << count << endl;

    return 0;
}