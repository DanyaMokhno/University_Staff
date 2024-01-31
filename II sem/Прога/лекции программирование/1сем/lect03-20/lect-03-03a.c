#include <stdio.h>

int main()
{
    int *p;
    int n;

    n = 31345;
    p = &n;
    printf("Address: %p, value n: %d\n",p,n);
    printf("Address: %p, value: %d\n",p,*((char*)p));
    puts("Press ENTER when ready");
    getchar();
    return 0;
}
