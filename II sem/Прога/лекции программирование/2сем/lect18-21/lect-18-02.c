# include <stdio.h>

typedef union
{
    int p1;
    float p2;
} T;

void fp(int z)
{
    int i;

    for(i=31;i>=0;i--) printf("%d", (z>>i)&(0x1));
    putchar('\n');
}

int main()
{
    T x;

    printf("Size of int: %ld\n", sizeof(int));
    printf("Size of float: %ld\n", sizeof(float));

    printf("Your float? ");
    scanf("%f", &x.p2);
    printf("%d\n", x.p1);
    fp(x.p1);

    return 0;
}

