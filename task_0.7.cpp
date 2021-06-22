//
// find orbital period using continued fractions
//

#include <iostream>

using namespace std;
int main() {

    float T = 365 + 1/(4 + 1/(7+1/(1+1/3.0)));

    // Print the results
    std::cout << "The orbital period  is " << T << std::endl;

    return 0;
}