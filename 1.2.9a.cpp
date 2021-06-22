#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double n, x, y;
  cin >> n >> x;
  for( int  i = 0; i < n; i++)
  {
    y += ( n - i ) * pow( x , n - i-1 );
   
  }
  cout << y + 2 * x << endl;
}
