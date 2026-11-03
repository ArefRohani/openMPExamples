#include <array>
#include <iostream>

#include <omp.h>

int main()
{
    omp_set_dynamic(0);
    std::array<int, 4> thread_ids{};

#pragma omp parallel num_threads(4)
    {
        const int thread_id = omp_get_thread_num();
        thread_ids[thread_id] = thread_id;
    }

    for (int thread_id : thread_ids)
        std::cout << thread_id << '\n';
}
