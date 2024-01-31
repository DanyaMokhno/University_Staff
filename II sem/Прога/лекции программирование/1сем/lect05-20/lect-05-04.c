#include <stdio.h>

void modif(int *x)
{
    *x=23;
}

int main()
{
    int a;

    a=2;
    printf("a=%d, address of a: %p\n",a,&a);
    modif(&a);
    printf("a=%d, address of a: %p\n",a,&a);

    puts("Press ENTER when ready");
    getchar();
    return 0;
}

