#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
using std::ofstream;
using std::ifstream;
using namespace std;

class Address {
    public:
        string city;
        string street;
        int building_number = 123;
        int flat_number = 333;

        void print() {
            cout << "city: " << city << "street: " << street;
            cout << " building number: " << building_number << " flat_number: " << flat_number;
        }

        void inputAddress()
        {
            cout << "City: ";
            cin >> city;
            cout << "Street: ";
            cin >> street;
            cout << "Building_number: ";
            cin >> building_number;
            cout << "Flat_number: ";
            cin >> flat_number;
        }
};

class InternationalAddress: public Address {
    public:
        string country;
        string postal_code;

        void print() {
            Address::print();
            cout << " country: " << country << " "<< "postal_code: " << postal_code << endl;
        }

        void inputAddress()
        {
            Address::inputAddress();
            cout << "Country: ";
            cin >> country;
            cout << "postal_code: ";
            cin >> postal_code;
        }
};


int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    Address* arr[n];
    for(int i = 0; i < n; ++i)
    {
        int option;
        cout << "Enter 1 if you want to enter simple address else InternationalAddress: ";
        cin >> option;
        if (option == 1)
        {
            Address* adr = new Address();
            adr->inputAddress();
            arr[i] = adr;
        }
        else
        {
            InternationalAddress* adr = new InternationalAddress();
            adr->inputAddress();
            arr[i] = adr;
        }
    }
    map<string,int> mp;
    for(int i=0;i<n;++i)
    {
        mp[arr[i].city]++;
    }
    string city;
    int max_count = 0;
    for(auto x:mp)
    {
        if(x.first > max_count)
        {
            max_count = x.first;
            city = x.second;
        }
    }
    ofstream out;
    out.open(path.c_str());
    string path;
    cout << "Path: ";
    cin >> path;

    for(int i = 0; i < n; ++i)
    {
        if(arr[i].city == city)
        {
            out << "city: " arr[i].city << " street: " << arr[i].street;
            out << " building_number: " << arr[i].building_number << " flat_number: " << arr[i].flat_number;
            if(typeid(arr[i]) == typeid(InternationalAddress))
            {
                out << " country: " arr[i].country << " postal_code: " << arr[i].postal_code;
            }
            out << endl;
        }
    }

    out.close();
    return 0;
}
