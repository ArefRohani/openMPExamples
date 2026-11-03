#include <iostream>

int main()
{
    int sum = 0;
    int product = 0;
    int difference = 0;

    int a = 5;
    int b = 20;

#pragma omp parallel sections num_threads(3)
    {
#pragma omp section
        {
            sum = a + b;
        }
#pragma omp section
        {
            product = a * b;
        }
#pragma omp section
        {
            difference = a - b;
        }
    }

    std::cout << sum << '\n';
    std::cout << product << '\n';
    std::cout << difference << '\n';
}
