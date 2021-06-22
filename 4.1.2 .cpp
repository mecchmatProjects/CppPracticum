#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
/*
vector<int> readNumbers(const string& filename) {
    fstream file(filename, ios::in);
    if (!file.is_open()) 
        exit(1);

    int n;
    vector<int> res;
    while (file >> n)
        res.push_back(n);

    file.close();

    return res;
}

void writeNumbers(const string& filename, const vector<int>::iterator begin,
    const vector<int>::iterator end) {
    fstream file(filename, ios::out);
    if (!file.is_open()) 
        exit(1);

    auto it = begin;
    while (it != end)
        file << *it++ << " ";

    file.close();
}

vector<int> getDivisors(int n) {
    vector<int> divisors;

    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            divisors.push_back(i);

    return divisors;
}

int main() {
    auto numbers = readNumbers("F");
    auto end = remove_if(numbers.begin(), numbers.end(), [](int el) {
        cout << el << " => ";
        for (auto& div : getDivisors(el)) {
            cout << div << " ";
        }
        cout << std::endl;
        return getDivisors(el).size() != 3;
        });

    writeNumbers("G", numbers.begin(), end);

    return 0;
}
*/