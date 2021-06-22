#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>

using namespace std;


int main(){
    double a,b;
    cout<<"Введіть інтервал:"<<endl;
    cin>>a;
    cin>>b;

    vector<double> numbers;
    cout<<"Введіть додатні числа через пробіли"<<endl;
    char input[120];
    cin >> input;
    char* tmp =strtok(input," ");
    numbers.push_back(log(atof(tmp)));

    while( tmp != NULL){
        tmp =strtok(NULL," ");
        numbers.push_back(log(atof(tmp)));
    }


    for( int  i =0; i< numbers.size();i++){
        if(numbers[i]>=a && numbers[i]<=b){
            printf("%e ( %f ) ",numbers[i],numbers[i]);
            cout<<endl;
        }
        else{
            cout<<"None"<<endl;
        }
    }
    return 0;
}