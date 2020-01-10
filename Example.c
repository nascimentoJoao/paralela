#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 4, tid = -1;

    #pragma omp parallel if(n >= 1) num_threads(n) \
            default(none) private(tid) shared(n)
    {
        // Get thread id
        tid = omp_get_thread_num();

        printf("Thread %d: Hello!\n", tid);

        if (n != omp_get_num_threads())
            printf("Error: NTHREADS\n");
    }

    printf("Thread %d: Bye!\n", tid);
}