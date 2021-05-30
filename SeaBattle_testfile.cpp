/*
 *  Задача № 32(SeaBattle)
 *  Кравцов Олег, статистика 2
 *  Файл для тестування програми
 */

#include <iostream>
#include "SeaBattle.h"

using namespace std;

void test()
{
    int exit = 0;
    cout << "Welcome to the Battle Ship game!" << endl;
    while (!exit)
    {
        cout << "We need to set some properties: " << endl;
        play();
        cout << endl;
        cout << "If you want to play again press 0 otherwise whatever you want: " << endl;
        cin >> exit;
    }
    cout << "Bye bye";
}

int main()
{
    test();
    return 0;
}