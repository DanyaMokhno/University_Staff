#include <stdio.h>

int main()
{
    int i;

    for(i=0;i<5;i++) printf("i=%d\n",i);
    puts("-----");
    for(i=0;i<5;++i) printf("i=%d\n",i);
    return 0;
}

