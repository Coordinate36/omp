#include <omp.h>
#include <iostream>

using namespace std;

const long num_steps = INT32_MAX >> 1;
double step;

int main() {
    double x, pi;
    double sum = 0.0;
    double start_time, end_time;
    step = 1.0 / num_steps;
    start_time = omp_get_wtime();
    for (int i = 0; i < num_steps; i++) {
        x = (i + 0.5) * step;
        sum += 4.0 / (1.0 + x * x);
    }
    pi = step * sum;
    end_time = omp_get_wtime();
    printf("Pi=%f\nRunning time:%f\n", pi, end_time - start_time);
    return 0;
}