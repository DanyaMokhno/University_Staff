#include <stdio.h>

int main()
{
    double F, G;
    double *pF, *pG;
    long dp;

    F=1.23;
    G=4.56;
    pF=&F;
    pG=&G;
    printf("Address1: %p (in decimal %ld), value: %lf\n", pF, (long)pF, *pF);
    printf("Address2: %p (in decimal %ld), value: %lf\n", pG, (long)pG, *pG);

    pF=pG;
    printf("Address1: %p (in decimal %ld), value: %lf\n", pF, (long)pF, *pF);
    pG=pG+0x2;
    printf("Address2: %p (in decimal %ld), value: %lf\n", pG, (long)pG, *pG);
    pF=&F;
    dp=pG-pF;
    printf("Difference of addresses: %ld\n", dp);
    printf("%ld\n",sizeof(double));
    puts("Press ENTER when ready");
    getchar();
    return 0;
}
