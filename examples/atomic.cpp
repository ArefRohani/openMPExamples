#include <iostream>
#include <omp.h>

int main() {
    int counter = 0;
    const int threads = omp_get_max_threads();

#pragma omp parallel num_threads(threads) shared(counter)
    {
        for (int count = 0; count < 10000; ++count) {
#pragma omp atomic update
            ++counter;
        }
    }

    std::cout << counter << '\n';
}
