#include <iostream>

using namespace std;

int main ()
{   double ak=1, S=0, b=1;
    int n = 25;
    for(int k=2;k<=n+1;k++)
    {
        ak=k*ak+1.0/k;
        S += b*ak;
        b = b*2/k;
        cout<<k-1<<' '<<ak<<' '<<S<<endl;
    }
}
