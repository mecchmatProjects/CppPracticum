#include <iostream>

using namespace std;


typedef struct Person{
    char sex;
    int height;
} Person;

void input(Person* person){
    cout << "sex = ";
    cin >> person -> sex;
    cout << "height = ";
    cin >> person -> height;
}

int main() {
    int n;
    int female = 0;
    cout << "n = ";
    cin >> n;
    Person persons[n];
    for(int i = 0; i < n; i++){
        input(&persons[i]);
    }
    int heightSum = 0;
    for (int i = 0; i < n; ++i) {
        if (persons[i].sex == 'f'){
            heightSum += persons[i].height;
            female += 1;
        }
    }
    cout << "average height = " << heightSum/female << endl;

    int maxHeight = 0;
    int name = 0;
    char sex = 0;
    for (int i = 0; i < n; ++i) {
        if (persons[i].sex == 'm'){
            if(persons[i].height > maxHeight){
                maxHeight = persons[i].height;
                sex = persons[i].sex;
                name = i;
            }
        }
    }
    cout << "max height = " << maxHeight << endl << "name = "<< name << endl << "sex = "<< sex << endl;
}