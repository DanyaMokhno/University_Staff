#include <stdio.h>

int main()
{
    int a,n;
    float b,c;
    double d;

    a=1;
    b=3.45;
    c=6.78;

    d=b*c;
    b=b+c;

    printf("%i\n",a*1.23); /* see warning! */
    printf("%i\n",(int)(a*1.23));
    printf("%f\n",d);
    printf("%f\n",b);

    a=(b<c);
    n=printf("Result %i\n",a);
    printf("%d\n",n);
    return 0;
}
