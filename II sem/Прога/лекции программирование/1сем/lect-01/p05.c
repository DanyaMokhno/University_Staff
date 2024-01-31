#include <stdio.h>

int main()
{
    char c;
    int a,n;
    float x;

    puts("Reading char");
    c=getchar();
    puts("Writing char");
    putchar(c);

    printf("\n%c %d\n",c,c);

    puts("Reading values");
    n=scanf("%d %f",&a,&x);
    puts("Writing values");
    printf("%d %f %d\n",a,x,n);
    return 0;
}
