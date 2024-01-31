#include <stdio.h>
#include <stdlib.h>

void modif(int *x)
{
    *x=23;
}

int main()
{
    int *a;
    if((a=(int*)malloc(sizeof(int)))!=NULL)
    {
        *a=2;
        printf("a=%d, address of a: %p\n",*a,a);
        modif(a);
        printf("a=%d, address of a: %p\n",*a,a);
        free(a);
        a=NULL;

        puts("Press ENTER when ready");
        getchar();
    }
    else puts("Error at memory allocation!");
    return 0;
}

