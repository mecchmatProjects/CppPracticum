/*
 *  Задача № 32(SeaBattle)
 *  Кравцов Олег, статистика 2
 *  Заголовковий файл з усіма функціями
 */

#ifndef SeaBattle_H_INCLUDED
#define SeaBattle_H_INCLUDED


#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>

using namespace std;

class Field {
private:
    // Amount of rows
    int rows;
    // Amount of columns
    int cols;
    //two dimensional array representing cells of the field
    int** cells;
    //x position of the ship
    int x_pos;
    //y position of the ship
    int y_pos;
    //method for creating two dimensional array
    int** create_cells(int rows, int cols);
public:
    Field();

    int getRows();

    int getCols();

    int get_x_pos();

    int get_y_pos();

    int get_cell(int x, int y);

    void set_cell(int x, int y, int value);

    void set_field();

    void set_field(int rows, int cols);

    void set_ship(int x, int y);

    void print_field();

    bool isShot(int x, int y);

    int distance_l1(int x, int y);

    bool possible_to_shoot(int x, int y);

    ~Field();
};

class Player {
public:
    Field* field;
    Field* enemy_field;

    Player();

    Player(int rows, int cols);

    bool moveShip(int x, int y);

    void autoMove();

    ~Player();
};

void play();

#endif // SeaBattle_H_INCLUDED

