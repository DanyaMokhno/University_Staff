# include <stdio.h>

int main()
{
    union
    {
        char s[4];
        float r;
        int i;
        char ch;
        unsigned j;
    } y;

    /*scanf("%s", y.s);*/
    fgets(y.s,5,stdin);
    printf("Field s: %s\n", y.s);
    printf("Field r: %f\n", y.r);
    printf("Field i: %d\n", y.i);
    printf("Field ch: %d\n", y.ch);
    printf("Field j: %u\n", y.j);

    return 0;
}

