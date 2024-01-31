#include <stdio.h>

int main()
{
    int a[8] = {1,2,3,4};
    int i;

    for(i=0;i<8;i++) printf("a[%d]= %d\n", i, a[i]);
    puts("Press ENTER when ready");
    getchar();

    return 0;
}
