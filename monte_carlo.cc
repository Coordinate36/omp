#include <omp.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

typedef long long LL;

const LL max_count = INT32_MAX;

int main()
{
    double start_time = omp_get_wtime();
    srand(time(nullptr));
    double x, y;
    LL count = 0;
    for (LL i = 0; i < max_count; i++) {
        x = rand() % INT32_MAX;
        x /= INT32_MAX;
        y = rand() % INT32_MAX;
        y /= INT32_MAX;
        if (x * x + y * y <= 1) {
            count++;
        }
    }
    double pi = double(count << 2) / max_count;
    double end_time = omp_get_wtime();
    printf("Pi=%lf\nRunning time:%lf\n", pi, end_time - start_time);
    return 0;
}