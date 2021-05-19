#include <iostream>
#include <array>
#include <algorithm>

template <unsigned N>
using matrix_t = std::array<std::array<unsigned, N>, N>;

template <unsigned N>
matrix_t<N> generateLatinSquare()
{
    matrix_t<N> result;
    unsigned x;
    std::for_each(result.begin(), result.end(), [&x](std::array<unsigned, N> &row) {
        unsigned y = 0;
        std::generate(row.begin(), row.end(), [&y] { return ++y; });
        std::rotate(row.begin(), row.begin() + row.size() - x++, row.end());
    });

    return result;
}

int main()
{
    auto matrix = generateLatinSquare<5>();

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
