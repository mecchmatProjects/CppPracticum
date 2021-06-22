#include <iostream>

using namespace std;

class Currency {
private:
    string name;
    int value{};
    int cents{};
public:
    void readCurrency();

    void printCurrency();

    int addition(const Currency &currency) const;

    int subtraction(const Currency &currency) const;

    int getValue() const;
};


void Currency::readCurrency() {
    cout << "name: ";
    cin >> name;
    cout << "value: ";
    cin >> value;
    cout << "cents: ";
    cin >> cents;
}

void Currency::printCurrency() {
    cout << name << " with value = " << value << " and cents = " << cents << endl;
}

int Currency::addition(const Currency &currency) const {
    return value * cents + currency.value * currency.cents;
}

int Currency::subtraction(const Currency &currency) const {
    return value * cents - currency.value * currency.cents;
}

int Currency::getValue() const {
    return value;
}

class Product {
private:
    string name;
    Currency currency;
    int price{};
    string count;
public:
    Product(Currency currency_) : currency(move(currency_)) {}

    void readProduct();

    void printProduct();

    int addition(const Product &product) const;

    int subtraction(const Product &product) const;
};

void Product::readProduct() {
    cout << "name: ";
    cin >> name;
    cout << "price: ";
    cin >> price;
    cout << "count: ";
    cin >> count;
}

void Product::printProduct() {
    cout << "name: " << name << endl;
    currency.printCurrency();
    cout << "price: " << price << endl;
    cout << "count: " << count << endl;
}

int Product::addition(const Product &product) const {
    return price * currency.getValue() + product.price * product.currency.getValue();
}

int Product::subtraction(const Product &product) const {
    return price * currency.getValue() - product.price * product.currency.getValue();
}


int main() {
    Currency c1, c2;
    c1.readCurrency();
    c2.readCurrency();
    cout << "first + second = " << c1.addition(c2) << endl;
    cout << "first - seconnd = " << c1.subtraction(c2) << endl;
    c1.printCurrency();
    c2.printCurrency();

    Product p1(c1), p2(c2);
    p1.readProduct();
    p2.readProduct();
    p1.printProduct();
    p2.printProduct();
    cout << "p1 + p2 = " << p1.addition(p2) << endl;
    cout << "p1 - p2 = " << p1.subtraction(p2) << endl;
    return 0;
}
