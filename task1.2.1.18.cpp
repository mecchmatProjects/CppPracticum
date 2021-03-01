#include <iostream>

using namespace std;

int main() {
int p, k, n, m;
do {
 cin >> n;
} while(n<=2);

 cout << 2 << ", ";
 m = 3;
  while(m <=n){
    p =1;
    k = 3;
    while(k*k <= m) {
        if (m%k == 0) {
          p = 0;
          break;
    }
    k = k+2;
  }
  if (p) cout << m << ", ";
  m += 2;
}
cout << "\n";

return 0;
} 
