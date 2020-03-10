#include <stdio.h>
#include <omp.h>

int main()
{
    int n = 10;
    int a[n], t[n];
    #pragma omp parallel shared(a,t,n)
    {
        int tid=0;
        #ifdef _OPENMP
            tid=omp_get_thread_num();
        #endif
        #pragma omp for
        for(int i=0; i<n; i++) {
            a[i]=2*i;
            t[i]=tid;
        }
    }

    printf("i,a(i),thread number\n");
    for(int i=0; i<n; i++) {
        printf("%i %i %i \n",i,a[i],t[i]);
    }
    return 0;
}
