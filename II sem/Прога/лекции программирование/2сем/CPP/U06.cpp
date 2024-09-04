#include <stdio.h>
#include <math.h>
// adding constructor
struct str_complex {
private:
    double re, im, mod, arg;
public:
    str_complex(double a_re, double a_im)
    {
        re=a_re;
        im=a_im;
        mod=sqrt(re*re + im*im);
        arg=atan2(im,re);
    }
    double get_re() { return re; }
    double get_im() { return im; }
    double argument() { return arg; }
    double modulo() { return mod; }
};

int main()
{
    enum {maxlen=32};
    char s0[32];
    //str_complex aaa; - mo more needed!!!
    double a,b,m;

    printf("Real part: ");
    fgets(s0,maxlen,stdin);
    a=atof(s0);

    printf("Imagine part: ");
    fgets(s0,maxlen,stdin);
    b=atof(s0);
    str_complex aaa(a,b); // initialization!! (call of constructor!!)
    m=aaa.modulo();
    a=aaa.argument();

    printf("Modulo: %f, argument: %f\n",m,a);
    return 0;
}



