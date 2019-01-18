#include <omp.h>
#include <iostream>

using namespace std;

#define NUM_THREADS 8

const long num_steps = INT32_MAX >> 1;
double step;

int main()
{
    double x, pi;
    double sum = 0.0;
    double start_time, end_time;
    step = 1.0 / (double)num_steps;
    omp_set_num_threads(NUM_THREADS);
    start_time = omp_get_wtime();
#pragma omp parallel for schedule(guided, 32) private(x) reduction(+ : sum)
    for (int i = 0; i < num_steps; i++)
    {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    end_time = omp_get_wtime();
    pi = sum * step;
    printf("Pi=%lf\nRunning time:%lf\n", pi, end_time - start_time);
    return 0;
}