#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p1, *p2;
    int value;

    p1=(int*)malloc(sizeof(int));
    *p1=123;
    value=456;
    p2=&value;
    printf("Address1 (Heap): %p, value: %d\n", p1, *p1);
    printf("Address2 (Stack): %p, value: %d\n", p2, *p2);
    free(p1);
    p1=NULL;
    puts("Press ENTER when ready");
    getchar();
    return 0;
}
