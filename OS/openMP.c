#include <stdlib.h>
#include <stdio.h>

int main()
{
    #pragma omp parallel
    {
        printf("I am parallel.\n");
    }
    
    return 0;
}