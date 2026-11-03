#include <array>
#include <iostream>

int main()
{
    std::array<int, 4> values{2, 3, 4, 5};
    std::array<int, 4> squares{};

#pragma omp parallel num_threads(4) shared(values, squares)
    {
#pragma omp single
        {
            for (int index = 0; index < static_cast<int>(values.size()); ++index)
            {
#pragma omp task firstprivate(index)
                {
                    squares[index] = values[index] * values[index];
                }
            }

#pragma omp taskwait
        }
    }

    for (int value : squares)
        std::cout << value << '\n';
    std::cout << '\n';
}
