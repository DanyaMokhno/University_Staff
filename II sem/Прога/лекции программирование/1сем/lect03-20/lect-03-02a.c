#include <stdio.h>

int main()
{
    int *p;
    int n;
    int m;

    m = 123;
    p = &m;
    printf("Address: %p, value: %d\n",p,m);
    n = *p;
    *p = -456;
    printf("Address: %p, value n: %d, value m: %d\n",p,n,m);
    puts("Press ENTER when ready");
    getchar();
    return 0;
}
