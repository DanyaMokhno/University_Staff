#include <stdio.h>
#include <math.h>
// Introduce class and new keyword
class Complex {
private:
    double re, im;
public:
    Complex(double a_re, double a_im)
    {
        re=a_re;
        im=a_im;
    }
    double get_re() { return re; }
    double get_im() { return im; }
    double argument() { return atan2(im,re); }
    double modulo() { return sqrt(re*re + im*im); }
};

int main()
{
    enum {maxlen=32};
    char s0[32];
    double a,b,m;
    //Complex *aaa;

    printf("Real part: ");
    fgets(s0,maxlen,stdin);
    a=atof(s0);

    printf("Imagine part: ");
    fgets(s0,maxlen,stdin);
    b=atof(s0);
    Complex aaa(a,b); // initialization!! (call of constructor!!)
    m=aaa.modulo();
    a=aaa.argument();
    // aaa= new Complex(a,b);
    // m=aaa->modulo();
    // a=aaa->argument();

    printf("Modulo: %f, argument: %f\n",m,a);
    // delete aaa; // cleaning memory!!
    return 0;
}




