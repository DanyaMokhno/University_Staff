#include <stdio.h>
#include <math.h>

struct str_complex {
    double re, im;
};

double modulo(str_complex *strc)
{
    return sqrt(strc->re*strc->re + strc->im*strc->im);
}

int main()
{
    enum {maxlen=32};
    char s0[32];
    str_complex aaa;
    double m;

    printf("Real part: ");
    fgets(s0,maxlen,stdin);
    aaa.re=atof(s0);

    printf("Imagine part: ");
    fgets(s0,maxlen,stdin);
    aaa.im=atof(s0);
    m=modulo(&aaa);

    printf("Modulo: %f\n",m);
    return 0;
}

