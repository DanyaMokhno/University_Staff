#include <stdio.h>

int main()
{
    int *p;
    int n,m,k;

    n = 31345;
    p = &n;
    k=5;
    m=p[k];
    printf("Address1: %p, value1: %d\n",p,n);
    printf("Address2: %p, value2: %d\n",&m,m);
    puts("Press ENTER when ready");
    getchar();
    return 0;
}

