#include <omp.h>
#include <stdio.h>

int main()
{

    // Current number of active threads
    printf("Num of threads is %d\n", omp_get_num_threads());

#pragma omp parallel
    {
        // Current thread ID
        printf("Thread ID: %d\n", omp_get_thread_num());

#pragma omp barrier
        if (omp_get_thread_num() == 0)
        {
            printf("\nNumber of active threads: %d\n", omp_get_num_threads());
        }
    }
}