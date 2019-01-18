#include <omp.h>
#include <iostream>

using namespace std;

#define NUM_THREADS 4

const long num_steps = INT32_MAX >> 1;
double step;

int main()
{
    double x;
    double pi = 0;
    double start_time, end_time;
    step = 1.0 / (double)num_steps;
    omp_set_num_threads(NUM_THREADS);
    start_time = omp_get_wtime();
#pragma omp parallel private(x)
    {
        int id = omp_get_thread_num();
        double sum = 0.0;
        for (int i = id; i < num_steps; i += NUM_THREADS)
        {
            x = (i + 0.5) * step;
            sum += 4.0 / (1.0 + x * x);
        }
        #pragma omp critical
        pi += sum;
    }
    end_time = omp_get_wtime();
    pi *= step;
    printf("Pi=%f\nRunning time:%f\n", pi, end_time - start_time);
    return 0;
}