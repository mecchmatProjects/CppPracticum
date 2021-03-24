#include <iostream>
#include <bitset>
#include <climits>

int main() {
    int num ;
    std::cin >> num;
    std::cout << std::bitset<sizeof(num) * CHAR_BIT>(num) << "\n";
}
