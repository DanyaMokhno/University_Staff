#include <stdio.h>

int main()
{
    int x[]={1,2,3,4,5,6,7,8};
    int *y;

    y=x;
    printf("Address of first element %p (or decimal) %ld\n", y,(long)y);
    printf("Address of last element %p (or decimal) %ld\n", y+7, (long)(y+7));
    printf("Value of first element %d\n", *y);
    printf("Value of last element %d\n", *(y+7));

    puts("Press ENTER when ready");
    getchar();
    return 0;
}
