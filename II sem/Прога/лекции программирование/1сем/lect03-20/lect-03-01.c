#include <stdio.h>

int main()
{
    float F;
    float *pF;
    int a[]={1,2,3,4,5,6,7,8};
    int *pa;

    F=1.23;
    pF=&F;
    printf("Address: %p, value: %f\n", pF, *pF);
    pa=a;
    printf("Address of array: %p\n", pa);
    puts("Press ENTER when ready");
    getchar();
    return 0;
}
