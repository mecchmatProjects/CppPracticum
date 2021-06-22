#include <string.h>
#include <iostream>
#include <fstream>

using namespace std;
 
struct PolMemb {
    int coef;
    int deg;
    int num;
};


int main()
{
    int polMembsNum=0;
    const int polsMembsNum=5;
    PolMemb polsMemLst[polsMembsNum]={};
    
    PolMemb pm; 
    
    int n;
    
    cout<<"Введіть номен поліному: ";
    cin>>n;
    
    const char *FName="f.bin";
    
    //УТВОРЮЄМО ФАЙЛ
    PolMemb a1;
    PolMemb a2;
    PolMemb b1;
    PolMemb b2;
    PolMemb b3;
    
    a1={2,1,1};
    a2={1,2,1};
    b1={0,5,2};
    b2={4,4,2};
    b3={1,6,2};
 
    ofstream f1(FName, ios::binary | ios::out);
        f1.write((char*)&a1, sizeof(a1));
        f1.write((char*)&a2, sizeof(a2));
        f1.write((char*)&b1, sizeof(b1));
        f1.write((char*)&b2, sizeof(b2));
        f1.write((char*)&b3, sizeof(b3));
    f1.close();
 
    
    ifstream f2(FName, ios::binary | ios::in);
        for(int i = 0;i<polsMembsNum;i++){
            f2.read((char*)&pm, sizeof(a1));
            cout << pm.coef << ' ' << pm.deg << ' ' << pm.num << '\n';
            polsMemLst[i]=pm;
        }
    f2.close();
    
  
    for(int i = 0;i<polsMembsNum;i++){
        if(polsMemLst[i].num==n){
            polMembsNum+=1;
        }
    }
    int k =0;
    PolMemb polMemLst[polMembsNum]={};
    for(int i = 0;i<polsMembsNum;i++){
        if(polsMemLst[i].num==n){
            polMemLst[k]=polsMemLst[i];
            k++;
        }
    }
    cout<<"Похідна: "<<endl;
    for(int i = 0;i<polMembsNum;i++){
        if(polMemLst[i].coef!=0){
            if(polMemLst[i].deg!=1&&polMemLst[i].deg!=0&&polMemLst[i].deg!=2){
                cout<<polMemLst[i].coef*polMemLst[i].deg<<"x^("<<polMemLst[i].deg-1<<")";
            }
            if(polMemLst[i].deg==1){
                cout<<polMemLst[i].coef;
            }
            if(polMemLst[i].deg==0){
                cout<<"0";
            }
            if(polMemLst[i].deg==2){
                cout<<polMemLst[i].coef*polMemLst[i].deg<<"x";
            }
            if(i<polMembsNum-1 && polMemLst[i-1].coef>=0){
                    cout<<"+";
                }
        }
        
    }
}
