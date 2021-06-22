#include <iostream>
#include <time.h>
#include <vector>


using namespace std;


int main(){
    int n = 5;
    cout<<"Input n:"<<endl;
    cin>>n;
    vector<vector<int>> arr(n);
    vector<int> uniq;

    for(int i =0;i<n;i++){
        cout<<"Input "<<i+1<<"line:"<<endl;
        for(int j=0;j<n;j++){
            int temp=0;
            cout<<"Input element"<<"[ "<<i+1<<","<<j+1<<" ]:"<<endl;
            cin>>temp;
            arr[i].push_back(temp);
            bool logic =true;

            for(auto& q: uniq){
                if(q == temp){
                    logic =false;
                    break;
                }
            }

            if(logic){
                uniq.push_back(temp);
            }
        }

    }

    int num;
    srand((unsigned)time(0));
    while(n>1){
        num =rand();
        num = num % uniq.size();

        int i_chosen=0,j_chosen=0;
        bool logic =false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==uniq[num]){
                    i_chosen=i;
                    j_chosen =j;
                    logic = true;
                    break;
                }
            }
            if(logic){
                break;
            }
        }

        if(logic){
            arr.erase(arr.begin()+i_chosen);
            n--;
            for(int j=0;j<n;j++){
                arr[j].erase(arr[j].begin()+j_chosen);
            }

            cout<<endl;
            cout<<"Matrix:"<<endl;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    cout<<arr[i][j]<<" ";
                }
                cout<<endl;
            }

        }


    }

    return 0;
}