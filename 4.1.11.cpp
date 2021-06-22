#include <iostream> 
#include <fstream> 
#include <stdio.h> 
#include <conio.h> 
#include <stdlib.h> 
 
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable : 4996) 
struct tois 
{ 
    std::string prod; 
    double price; 
    int min_age; 
    int max_age; 
    tois() :prod("None"), price(0), min_age(0), max_age(0){}; 
    tois(std::string p, int _p, int min, int max) : prod(p), price(_p), min_age(min), max_age(max) {}; 
}; 
 
void price_coobs(tois* t, int size) 
{ 
    FILE* F = fopen("1.bin", "wb"); 
    double pr_coobs = 0; 
    for (int i = 0; i < size; i++) 
    { 
        if (t[i].prod == "Coobs") 
            pr_coobs = pr_coobs + t[i].price; 
    } 
    std::cout << "Price all coobs: " << pr_coobs; 
    fwrite(&pr_coobs, sizeof(double), 1, F); 
    fclose(F); 
} 
 
void two_tois_to_3(tois* t, int size, int X) 
{ 
    FILE* F = fopen("1.bin", "wb"); 
    int counter = 0; 
    for (int i = 0; i < size; i++) 
    { 
        if (t[i].min_age == 1 && t[i].max_age == 3 && t[i].price < X) 
        { 
            std::string s = t[i].prod; 
            std::cout << "\nToy: " << t[i].prod; 
            fwrite(&s, sizeof(std::string), 1, F); 
            counter++; 
        } 
        if (counter == 2) 
            break; 
    } 
    fclose(F); 
} 
 
int main() 
{ 
    std::ifstream file("toys.txt"); 
    std::string p; 
    double pr = 0; 
    int min = 0; 
    int max = 0; 
    int size = 0; 
    int X = 5000; 
    while (!file.eof()) 
    { 
        if (file.eof()) 
            break; 
        file >> size; 
        tois* t = new tois[size]; 
        for (int i = 0; i < size; i++) 
        { 
            file >> p; 
            file >> pr; 
            file >> min; 
            file >> max; 
            t[i] = tois(p, pr, min, max); 
        } 
        price_coobs(t, size); 
        two_tois_to_3(t, size, X); 
        break; 
    } 
}