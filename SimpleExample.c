#include <stdio.h>

// You don't need to: #include <omp.h> in this example. :)
// With the #pragma omp parallel directive your code will
// run the same number as OMP_NUM_THREADS simultaneously.

int main()
{
    #pragma omp parallel
    {
        printf("Doing some stuff\n");
    }
    return 0;
}