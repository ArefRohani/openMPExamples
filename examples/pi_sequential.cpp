#include <iostream>

// a program to find pi based on integral zero to one of four over one plus x squared.

static long num_steps = 1000;
double step;
int main()
{
    double x, pi, sum = 0;
    step = 1 / (double)num_steps;
    for (int i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum += 4 / (1 + x * x);
    }
    pi = step * sum;
    std::cout << pi << '\n';
}