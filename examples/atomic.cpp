#include <iostream>
#include <omp.h>

int main() {
    int counter = 0;

#pragma omp parallel num_threads(omp_get_max_threads()) shared(counter)
    {
        for (int count = 0; count < 10000; ++count) {
#pragma omp atomic update
            ++counter;
        }
    }

    std::cout << counter << '\n';
}
