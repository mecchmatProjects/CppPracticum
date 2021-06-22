#include<fstream>
#include<string.h>
#include<stdio.h>
#include<iostream>
#include <algorithm>
#include <string>

using namespace std;

void Rline()
{
    fstream fil;
    fil.open("C:/Users/okot/Desktop/Uni/untitled4/6.40_input.txt",ios::in);
    fstream f;
    f.open ("C:/Users/okot/Desktop/Uni/untitled4/6.40_output.txt",ios::app);
    char W[80];
    while(!fil.eof())
    {   fil.getline(W,80);
        for (int i=strlen(W)-1;i>=0;i--){
            if(W[i] == '0')
                W[i] = '1';
            f << W[i];
        }
        f << '\n';
    }

}
int main()
{
    Rline();
    return 0;
}