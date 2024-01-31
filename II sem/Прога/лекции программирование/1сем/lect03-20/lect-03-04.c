#include <stdio.h>

int main()
{
    int *p;
    int n;

    n = 31345;
    p = &n;
    printf("Address: %p, size: %ld\n",p,sizeof(p));
    puts("Press ENTER when ready");
    getchar();
    return 0;
}
