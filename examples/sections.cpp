#include <cstdio>

int main() {
    int sum = 0;
    int product = 0;
    int difference = 0;

#pragma omp parallel sections num_threads(3)
    {
#pragma omp section
        {
            sum = 20 + 5;
        }
#pragma omp section
        {
            product = 20 * 5;
        }
#pragma omp section
        {
            difference = 20 - 5;
        }
    }

    std::printf("Sum: %d\n", sum);
    std::printf("Product: %d\n", product);
    std::printf("Difference: %d\n", difference);
    return 0;
}
