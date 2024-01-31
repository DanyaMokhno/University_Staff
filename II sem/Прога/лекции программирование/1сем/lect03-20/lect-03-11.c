#include <stdio.h>

#define MSIZE 12

int main()
{
    int a[MSIZE];
    int i;

    i=0;
    while(i<MSIZE)
    {
        a[i]=0;
        printf("%3d", a[i]);
        i++;
    }
    puts("\nPress ENTER when ready");
    getchar();
    return 0;
}
