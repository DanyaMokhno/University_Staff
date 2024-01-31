#include <stdio.h>

#define MSIZE 12

int main()
{
    int a[MSIZE];
    int i;

    for(i=0;i<MSIZE;i++)
    {
        a[i]=0;
        printf("%3d", a[i]);
    }
    puts("\nPress ENTER when ready");
    getchar();
    return 0;
}
