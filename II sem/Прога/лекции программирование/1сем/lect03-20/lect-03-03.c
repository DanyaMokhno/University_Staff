#include <stdio.h>

int main()
{
    float F;
    float *pF;

    F=1.23;
    pF=&F;
    printf("Address1: %p (in decimal %ld), value: %lf\n", pF, (long)pF, *pF);
    pF++;
    printf("Address2: %p (in decimal %ld), value: %lf\n", pF, (long)pF, *pF);
    puts("Press ENTER when ready");
    getchar();
    return 0;
}

