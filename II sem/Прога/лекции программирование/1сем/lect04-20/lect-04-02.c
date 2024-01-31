#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1;
    int value;

    p1=(int*)malloc(sizeof(int));
    *p1=123;
    value=*p1;
    printf("Address1 (Heap): %p, value: %d\n", p1, value);
    free(p1);
    p1=NULL;
    puts("Press ENTER when ready");
    getchar();
    return 0;
}
