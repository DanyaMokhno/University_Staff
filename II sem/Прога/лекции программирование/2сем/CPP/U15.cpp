#include <stdio.h>
#include <math.h>

class Complex {
private:
    double re, im, mod, arg;
public:
    Complex(double a_re, double a_im)
    {
        re=a_re;
        im=a_im;
        mod = sqrt(re*re + im*im);
        arg = atan2(im,re);
    }
    Complex() { re=0; im=0; }
    Complex(double a) { re=a; im=0; }
    double get_re() { return re; }
    double get_im() { return im; }
    void set_re(double param) { re=param; }
    void set_im(double param) { im=param; }
    // update methods
    double argument()
    {
        double arg2;
        arg2=arg;
        return arg2;
    }
    double modulo()
    {
        double m2;
        m2=mod;
        return m2;
    }
    // add methods
    void set_arg(double param) { arg=param; }
    void set_mod(double param) { mod=param; }
    ~Complex() {}
};

// function outside of class

Complex cmpl_pow(Complex z, double n)
{
    Complex res;
    double m,a;

    m=z.modulo();
    a=z.argument();

    if(n>=0)
    {
        m=pow(m,n);
        a=a*n;
    }
    else
    {
        m=0;
        a=0;
    }
    z.set_re(0);
    z.set_im(0);
    res.set_mod(m);
    res.set_arg(a);

    return res;
}

int main()
{
    enum {maxlen=32};
    char s0[32];
    double a,b;

    printf("Real part: ");
    fgets(s0,maxlen,stdin);
    a=atof(s0);

    printf("Imagine part: ");
    fgets(s0,maxlen,stdin);
    b=atof(s0);

    Complex cv(a,b);
    printf("Object: cv, Modulo: %f, argument: %f\n",cv.modulo(),cv.argument());

    Complex zz=cmpl_pow(cv, 0.5);
    printf("Object: zz, Modulo: %f, argument: %f\n",zz.modulo(),zz.argument());
    // check state
    printf("Object: cv, Modulo: %f, argument: %f\n",cv.modulo(),cv.argument());

    return 0;
}









