#include <stdio.h>

int main()
{
    int x[2][3]={{1,2,3},{4,5,6}};
    int *y[2];
    int **z;

    y[0]=x[0];
    puts("First row");
    printf("Address of first element %p (or decimal) %ld\n", y[0],(long)y[0]);
    printf("Address of last element %p (or decimal) %ld\n", y[0]+2, (long)(y[0]+2));
    printf("Value of first element %d\n", *y[0]);
    printf("Value of last element %d\n", (*y[0]+2));

    y[1]=x[1];
    puts("Next row");
    printf("Address of first element %p (or decimal) %ld\n", y[1],(long)y[1]);
    printf("Address of last element %p (or decimal) %ld\n", y[1]+2, (long)(y[1]+2));
    printf("Value of first element %d\n", *y[1]);
    printf("Value of last element %d\n", *(y[1]+2));

    z=y;
    printf("Address of first element %p (or decimal) %ld\n", z[0],(long)z[0]);
    printf("Address of last element %p (or decimal) %ld\n", z[0]+5, (long)(z[0]+5));
    printf("Value of first element %d\n", **z);
    printf("Value of last element %d\n", *(*z+5));

    puts("Press ENTER when ready");
    getchar();
    return 0;
}

