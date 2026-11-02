#include <omp.h>

#include <array>
#include <cstdio>

int main() {
    omp_set_dynamic(0);
    const int starting_value = 10;
    std::array<int, 4> results{};

#pragma omp parallel num_threads(4) firstprivate(starting_value) shared(results)
    {
        const int thread_id = omp_get_thread_num();
        int local_value = starting_value;
        local_value += thread_id;
        results[thread_id] = local_value;
    }

    for (int value : results) {
        std::printf("%d ", value);
    }
    std::printf("\n");
    return 0;
}
