#include <iostream> 
//#include <cmath> 
using namespace std; 
int main() { 
  int m_1; int m_2; int r;
  float y = 6.673e-11;// * pow(10,(-11));
  float F;
  cout <<" m_1 = "; cin >> m_1; 
  cout << " m_2 = "; cin >> m_2; 
 cout << " r = "; cin >> r; 
  F = (y * m_1 * m_2) / (r*r);
  cout << "F = "; cout << F; 
} 



