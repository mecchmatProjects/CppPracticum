#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
 
using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2;
    int a1;
    int n = 10;
    
    std::cout << "Input v1: ";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ") ";
        cin >> a1;
        v1.push_back(a1);
    }
    std::cout << endl;
    
    
    std::cout << "Input v2: ";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ") ";
        cin >> a1;
        v2.push_back(a1);
    }
    std::cout << endl;
    
    vector<int> out;
    std::set_union(std::begin(v1), std::end(v1), std::begin(v2), std::end(v2),
                   std::back_inserter(out));
    sort (out.begin(), out.end());  // сортировка
      cout << endl << "after sorting: ";
     
      for (int i = 0; i < out.size(); i++) {
        cout << out[i] << " ";
      }
    
    return 0;
}

