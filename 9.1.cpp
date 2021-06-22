#include <math.h>
#include <iostream>
#include <cmath>
#include <stdio.h>
//#include <locale>
using namespace std;
struct Numbers {
    string name;
    size_t phone;
};

class Person {
private:
    string name;
    unsigned byear;

public:
    Person(string y = 'lena', unsigned x = 2002) : name(y), byear(x) {
    }

    friend std::ostream &operator<<(std::ostream &out, const Person &person);
};

std::ostream &operator<<(std::ostream &out, const Person &person) {
    out << "Person" << person.name << ", " << person.byear << ;

    return out;
}

class Friend : public Person {
private:
    size_t phone;
    size_t number_of_numbers;
    Numbers *nums;


    void set_number_info() {
        for (size_t i = 0; i < number_of_numbers; ++i) {
            cout << "Enter name: ";
            cin >> nums[i].name;
        }
    }

    void set_number_of_courses() {
        cout << "Enter number of numbers: ";
        cin >> number_of_numbers;
    }


public:
    Friend
            (
                    const size_t phone_ = 12345,
                    const size_t number_of_numbers_ = 1
            ) :
            Person
                    (
                            name_,
                            byear_
                    ),
            number_of_numbers(number_of_numbers_) {
        nums = new Numbers[number_of_numbers];
    }

    ~Friend() {
        delete[] nums;
    }

    void set_personal_data() {
        Person person("dsfa", 20200);
        set_number_of_courses();

        delete[] nums;
        nums = new Numbers[number_of_numbers];

        set_number_info();
    }

};

int main() {
    Person p1('lena', 2002);

    std::cout << p1;
    Friend f1;
    f1.set_personal_data();

    return 0;
}