#include <omp.h>

#include <array>
#include <cstdio>

int main() {
    omp_set_dynamic(0);
    std::array<int, 12> owners{};

#pragma omp parallel for num_threads(4) schedule(static, 2)
    for (int iteration = 0; iteration < static_cast<int>(owners.size()); ++iteration) {
        owners[iteration] = omp_get_thread_num();
    }

    for (int iteration = 0; iteration < static_cast<int>(owners.size()); ++iteration) {
        std::printf("Iteration %d used thread %d\n", iteration, owners[iteration]);
    }
    return 0;
}
