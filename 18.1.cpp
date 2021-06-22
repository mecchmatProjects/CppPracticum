
#include <iostream>
#include <tchar.h>


using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
    setlocale(0,"rus");
    int *T,*C,N,j=1,min;
    cout<<"input n"<<endl;
    cin>>N;
    T=new int[N];
    C=new int[N];
    for (int i=0;i<N;i++)
    {
        cout<<"Input time "<<j;
        cin>>T[i];
        j++;
    }
    min=1000;
    for (int i=0;i<N;i++)
    {
        if (T[i]<min)
        {
            min=T[i];
            j=i+1;
        }
    }
    cout<<"least time "<<j<<" time:"<<min<<" min"<<endl;
    C[0]=T[0];
    cout<<"1st in queue was on :"<<C[0]<<endl;
    j=2;
    for (int i=1;i<N;i++)
    {
        C[i]=T[i]+C[i-1];
        cout<<j<<" in queue was on :"<<C[i]<<"min."<<endl;
        j++;
    }
    cin.get();
    cin.get();
    return 0;
}