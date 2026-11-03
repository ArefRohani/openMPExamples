#include <array>
#include <iostream>

#include <omp.h>

int main()
{
    std::array<int, 8> left{1, 2, 3, 4, 5, 6, 7, 8};
    std::array<int, 8> right{8, 7, 6, 5, 4, 3, 2, 1};
    std::array<int, 8> sum{};

#pragma omp parallel for num_threads(omp_get_max_threads())
    for (int index = 0; index < static_cast<int>(sum.size()); ++index)
    {
        sum[index] = left[index] + right[index];
    }

    for (int value : sum)
    {
        std::cout << value << '\n';
    }
    std::cout << '\n';
}
