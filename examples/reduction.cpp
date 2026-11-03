#include <iostream>

#include <omp.h>

int main()
{
    int sum = 0;

#pragma omp parallel for num_threads(omp_get_max_threads()) reduction(+ : sum)
    for (int value = 1; value <= 100; ++value)
        sum += value;

    std::cout << sum << '\n';
}
