#include <iostream>

int main()
{   
    int sz = 5;
    int arrX[] = { 1, 2, 3, 4, 5 };
    int arrY[] = { 3, 1, 5, 4, 2 };

    std::cout << "x";
    for (size_t i = 0; i < sz; i++)
    {
        std::cout << "|" << arrX[i];
    }
    std::cout << std::endl;

    std::cout << "----------" << std::endl;

    std::cout << "y";
    for (size_t i = 0; i < sz; i++)
    {
        std::cout << "|" << arrY[i];
    }
    std::cout << std::endl;
    return 0;
}