#include <stdio.h>

int modif(int x)
{
    x=23;
    return x;
}

int main()
{
    int a,b;

    a=2;
    printf("a=%d, address of a: %p\n",a,&a);
    b=modif(a);
    printf("a=%d, address of a: %p, b=%d, address of b: %p\n",a,&a,b,&b);

    puts("Press ENTER when ready");
    getchar();
    return 0;
}


