#include <cstdio>

int main() {
    int counter = 0;

#pragma omp parallel num_threads(4) shared(counter)
    {
        for (int count = 0; count < 10000; ++count) {
#pragma omp critical
            {
                ++counter;
            }
        }
    }

    std::printf("Counter: %d\n", counter);
    return 0;
}
