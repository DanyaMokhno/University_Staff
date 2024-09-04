#include <stdio.h>

int main()
{
    enum {F, T};

    printf("%d\n", T);
/*    printf("%ld\n", sizeof(enum)); */
    return 0;
}
