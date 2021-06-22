#include <iostream>
using namespace std;
#define N 5
int main()
{
    int m[N];
    for ( int i = 0; i < N; i++)
    {
      cin >> m[i];
    }

    int sump = 0;
    int sumn = 0;
    for(int i = 0; i < N; i++)
    {
        if(m[i]%2 != 0)
            sumn += m[i];
        else
            sump += m[i];
    }
    cout <<"sump = " << sump << endl;
    cout <<"sumn = " << sumn << endl;
    return 0;
}