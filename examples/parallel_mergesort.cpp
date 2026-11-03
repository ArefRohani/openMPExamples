#include <algorithm>
#include <iostream>
#include <random>

#include <omp.h>

template <typename Function>
double benchmark(Function function)
{
    const double start = omp_get_wtime();
    function();
    const double end = omp_get_wtime();
    return end - start;
}

void parallel_sort(std::vector<int> &data)
{
    const int threads = omp_get_max_threads();
    const std::size_t size = data.size();
    const std::size_t chunk = size / threads;

#pragma omp parallel for
    for (int i = 0; i < threads; ++i)
    {
        const std::size_t begin = i * chunk;
        const std::size_t end = (i == threads - 1) ? size : begin + chunk;

        std::sort(data.begin() + begin, data.begin() + end);
    }

    for (std::size_t width = chunk; width < size; width *= 2)
    {
#pragma omp parallel for
        for (std::int64_t begin = 0;
             begin < static_cast<std::int64_t>(size);
             begin += static_cast<std::int64_t>(2 * width))
        {
            const std::size_t start = static_cast<std::size_t>(begin);

            const std::size_t middle = std::min(start + width, size);

            const std::size_t end = std::min(start + 2 * width, size);

            std::inplace_merge(
                data.begin() + start,
                data.begin() + middle,
                data.begin() + end);
        }
    }
}

int main()
{
    constexpr std::size_t element_count = 10'000'000;

    std::cout << "OpenMP Parallel Sort" << '\n';
    std::cout << "Elements : " << element_count << '\n';
    std::cout << "Threads  : " << omp_get_max_threads() << '\n';

    std::vector<int> original(element_count);

    std::mt19937 rng(12345);
    std::uniform_int_distribution<int> distribution(0, 1'000'000'000);

    for (auto &value : original)
        value = distribution(rng);

    auto sequential = original;

    const double sequential_time = benchmark([&]
                                             { std::sort(sequential.begin(), sequential.end()); });

    auto parallel = original;

    const double parallel_time = benchmark([&]
                                           { parallel_sort(parallel); });

    const bool correct = sequential == parallel;

    std::cout << "Sequential : " << sequential_time << " seconds" << '\n';
    std::cout << "OpenMP     : " << parallel_time << " seconds" << '\n';
    std::cout << "Speedup    : " << sequential_time / parallel_time << "x" << '\n';
    std::cout << "Correct    : " << (correct ? "YES" : "NO") << '\n';

    return correct ? 0 : 1;
}