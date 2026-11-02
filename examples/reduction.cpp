#include <cstdio>

int main() {
    int sum = 0;

#pragma omp parallel for num_threads(4) reduction(+:sum)
    for (int value = 1; value <= 100; ++value) {
        sum += value;
    }

    std::printf("Sum: %d\n", sum);
    return 0;
}
