#include <stdio.h>
#include <math.h>
// adding constructor
struct str_complex {
private:
    double re, im;
public:
    str_complex(double a_re, double a_im)
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

    printf("Modulo: %f\n",m);
    return 0;
}


