#include<stdio.h>


int main()
{
    int A[10][10];
    int len=10,k=0,p=0;

    while(k<100)
    {
        for(int i=p;i<len;i++)
        {
            A[p][i]=100 - k++;
        }
        for(int i=p+1;i<len;i++)
        {
            A[i][len-1]=100 - k++;
        }
        for(int i=len-2;i>=p;i--)
        {
            A[len-1][i]=100 - k++;
        }
        for(int i=len-2;i>p;i--)
        {
            A[i][p]=100 - k++;
        }

        p++;
        len--;
    }

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            printf("%d\t",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
