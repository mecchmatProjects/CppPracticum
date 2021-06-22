#include <iostream>
#include <iterator>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
int is_prime(int n) {
    int flag=0;
    if ( n % 2 == 0)
        flag=1;
    return flag;
}
int erase(vector<double> numbers) {
    fstream fout;
    fout.open("numbers_new.txt", ios::out);
    numbers.erase( numbers.begin() + numbers.size()/2-1 );
    numbers.erase( numbers.begin() + numbers.size()/2 );
    numbers.erase( numbers.begin() + numbers.size()/2+1 );
    for(int i=0;i<numbers.size();++i){
        fout<<numbers[i]<<endl;
    }
    fout.close();
    remove("numbers.txt");
    rename("numbers_new.txt",
           "numbers.txt");
}
int main()
{
    fstream fout;
    std::ifstream is("numbers.txt");
    fout.open("numbers_new.txt", ios::out);
    std::istream_iterator<double> start(is), end;
    std::vector<double> numbers(start, end);
    std::cout << "Read " << numbers.size() << " numbers" << std::endl;
    if (is_prime(numbers.size())==1){
        std::cout << "numbers read in:\n";
        std::copy(numbers.begin(), numbers.end(),
                  std::ostream_iterator<double>(std::cout, " "));
        std::cout << std::endl;
    }
    if (is_prime(numbers.size())==0){
        int a,b,c;
        cout<< "Enter a";
        cin>>a;
        cout<< "Enter b";
        cin>>b;
        cout<< "Enter c";
        cin>>c;
        numbers.push_back(a);
        numbers.push_back(b);
        numbers.push_back(c);
        for(int i=0;i<numbers.size();++i){
            fout<<numbers[i]<<endl;
        }
        fout.close();
        remove("numbers.txt");
        rename("numbers_new.txt",
               "numbers.txt");

    }

    }

}