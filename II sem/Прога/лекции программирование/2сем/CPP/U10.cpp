#include <stdio.h>
#include <math.h>
// Adding constructor to default

class Complex {
private:
    double re, im;
public:
    Complex(double a_re, double a_im)
    {
        re=a_re;
        im=a_im;
    }
    Complex() { re=0; im=0; }
    double get_re() { return re; }
    double get_im() { return im; }
    double argument() { return atan2(im,re); }
    double modulo() { return sqrt(re*re + im*im); }
    ~Complex() {}; // destructor do nothing
};

int main()
{
    enum {maxlen=32};
    char s0[32];
    double a,b,m;
    Complex *aaa;

    printf("Real part: ");
    fgets(s0,maxlen,stdin);
    a=atof(s0);

    printf("Imagine part: ");
    fgets(s0,maxlen,stdin);
    b=atof(s0);
    aaa = new Complex(a,b); // initialization!! (call of constructor!!)
    m=aaa->modulo();
    a=aaa->argument();

    printf("Modulo: %f, argument: %f\n",m,a);
    delete aaa; // destructor!!!

    aaa = new Complex();
    m=aaa->modulo();
    a=aaa->argument();

    printf("Modulo: %f, argument: %f\n",m,a);
    delete aaa; // destructor!!!

    return 0;
}





