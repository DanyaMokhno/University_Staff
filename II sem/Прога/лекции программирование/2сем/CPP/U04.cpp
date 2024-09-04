#include <stdio.h>
#include <math.h>

struct str_complex {
private:
    double re, im;
public:
    void dset(double a_re, double a_im)
    {
        re=a_re;
        im=a_im;
    }
    double modulo() { return sqrt(re*re + im*im); }
};

int main()
{
    enum {maxlen=32};
    char s0[32];
    str_complex aaa;
    double a,b,m;

    printf("Real part: ");
    fgets(s0,maxlen,stdin);
    a=atof(s0);

    printf("Imagine part: ");
    fgets(s0,maxlen,stdin);
    b=atof(s0);
    // in this point aaa is in undefined state
    aaa.dset(a,b);
    m=aaa.modulo();

    printf("Modulo: %f\n",m);
    return 0;
}


