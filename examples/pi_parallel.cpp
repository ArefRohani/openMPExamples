#include <iostream>
#include <omp.h>

static long num_steps = 1000;
#define NUM_THREADS omp_get_max_threads()

int main()
{
    double pi = 0.0;
    double sum[NUM_THREADS] = {};

    double step = 1.0 / static_cast<double>(num_steps);

    omp_set_num_threads(NUM_THREADS);

    int nthreads = 0;

#pragma omp parallel
    {
        int id = omp_get_thread_num();
        int nthrds = omp_get_num_threads();
        double x;

        if (id == 0)
            nthreads = nthrds;

        sum[id] = 0.0;

        for (long i = id; i < num_steps; i += nthrds)
        {
            x = (i + 0.5) * step;
            sum[id] += 4.0 / (1.0 + x * x);
        }
    }

    for (int i = 0; i < nthreads; i++)
        pi += sum[i];

    pi *= step;

    std::cout << "Pi = " << pi << '\n';
}
