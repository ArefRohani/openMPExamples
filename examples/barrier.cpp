#include <array>
#include <iostream>

#include <omp.h>

int main()
{
    omp_set_dynamic(0);
    std::array<int, 4> values{};
    std::array<int, 4> observed{};

#pragma omp parallel num_threads(4) shared(values, observed)
    {
        const int thread_id = omp_get_thread_num();
        values[thread_id] = thread_id + 10;

#pragma omp barrier

        observed[thread_id] = values[(thread_id + 1) % 4];
    }

    for (int value : observed)
    {
        std::cout << value << '\n';
    }
    std::cout << '\n';
}
