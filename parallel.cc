#include <omp.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    int nthreads;
    int tid;

#pragma omp parallel private(nthreads, tid)
    {
        tid = omp_get_thread_num();
        printf("hello world from OpenMP thread %d\n", tid);
        if (tid == 0)
        {
            nthreads = omp_get_num_threads();
            printf("Number of threads %d\n", nthreads);
        }
    }

    return 0;
}