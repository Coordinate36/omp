#include <omp.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main()
{
    srand(time(NULL));
#pragma omp parallel for
    for (int i = 0; i < 10; ++i)
    {
        int t = rand() % 3;
        sleep(t);
        cout << i << flush;
    }
    cout << endl;
    return 0;
}