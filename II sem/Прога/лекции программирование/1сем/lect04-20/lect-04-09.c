#include <stdio.h>

int main()
{
    int x[2][3]={{1,2,3},{4,5,6}};
    int *y;
    int **z;

    y=x[0];
    puts("First row");
    printf("Address of first element %p (or decimal) %ld\n", y,(long)y);
    printf("Address of last element %p (or decimal) %ld\n", y+2, (long)(y+2));
    printf("Value of first element %d\n", *y);
    printf("Value of last element %d\n", *(y+2));

    y=x[1];
    puts("Next row");
    printf("Address of first element %p (or decimal) %ld\n", y,(long)y);
    printf("Address of last element %p (or decimal) %ld\n", y+2, (long)(y+2));
    printf("Value of first element %d\n", *y);
    printf("Value of last element %d\n", *(y+2));

    y=x[0];
    z=&y;
    printf("Address of first element %p (or decimal) %ld\n", z[0],(long)z[0]);
    printf("Address of last element %p (or decimal) %ld\n", z[0]+5, (long)(z[0]+5));
    printf("Value of first element %d\n", **z);
    printf("Value of last element %d\n", *(*z+5));

    puts("Press ENTER when ready");
    getchar();
    return 0;
}

