#include <stdio.h>
#include <math.h>

struct str_complex {
private:
    double re, im;
public:
    double modulo() { return sqrt(re*re + im*im); }
};

int main()
{
    enum {maxlen=32};
    char s0[32];
    str_complex aaa;
    double m;

    printf("Real part: ");
    fgets(s0,maxlen,stdin);
    aaa.re=atof(s0); // error: 'double str_complex::re' is private within this context|

    printf("Imagine part: ");
    fgets(s0,maxlen,stdin);
    aaa.im=atof(s0);
    m=aaa.modulo();

    printf("Modulo: %f\n",m);
    return 0;
}

