#include <stdio.h>

int main()
{
    int d1, o1, h1;

    d1=234;
    o1=067;
    h1=0xDE;

    printf("Our data: %d, %o, %X\n", d1, o1, h1);
    printf("Our data 2: %d, %d, %d\n", d1, o1, h1);
    return 0;
}
