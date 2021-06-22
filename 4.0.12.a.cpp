#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Product {
private:
    int priceHrn;
    int priceKop;
    string name;
public:
    Product(string name = "", int priceHrn = 0, int priceKop = 0): name(name), priceHrn(priceHrn), priceKop(priceKop) {};

    int getPriceHrn() const {
        return priceHrn;
    }

    int getPriceKop() const {
        return priceKop;
    }

    string getName() const {
        return name;
    }

    bool operator<(Product& other) {
        if (priceHrn < other.getPriceHrn()) {
            return 1;
        } else if (priceHrn == other.getPriceHrn() && priceKop < other.getPriceKop()) {
            return 1;
        }
        return 0;
    }
};

ostream& operator<<(std::ostream& out, const Product& product) {
    out << "Name: " << product.getName() << endl << "\t" << "Price: " << product.getPriceHrn() << ":" << product.getPriceKop();
    return out;
}

int main() {
    vector<Product> vec;
    for ( int i = 0; i < 5; i++) {
        vec.push_back(Product(string("a"), rand() % 100, rand() % 100));
    }

    for ( int i = 0; i < 5; i++) {
        cout << vec[i] << endl;
    }

    int min = 0;

    for ( int i = 1; i < 5; i++) {
        if (vec[i] < vec[min]) {
            min = i;
        }
    }

    cout << "MIN: " << endl;
    cout << vec[min] << endl;

    return 0;
}

