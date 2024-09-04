#include <stdio.h>

int main()
{
    enum boolean {F, T};

    printf("%d\n", T);
    printf("%ld\n", sizeof(enum boolean));
    return 0;
}
