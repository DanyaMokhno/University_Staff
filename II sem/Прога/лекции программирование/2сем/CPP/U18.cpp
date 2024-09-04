#include <stdio.h>
#include <math.h>

class Complex {
private:
    double re, im;
public:
    Complex(double a_re=0, double a_im=0)
    {
        re=a_re;
        im=a_im;
    }
    double get_re() { return re; }
    double get_im() { return im; }
    double argument() { return atan2(im,re); }
    double modulo() { return sqrt(re*re + im*im); }
    void set_re(double param) { re=param; }
    void set_im(double param) { im=param; }
    //--------------
    Complex operator+(Complex op2)
    {
        Complex res(re+op2.re, im+op2.im);
        return res;
    }
    Complex operator-(Complex op2)
    {
        Complex res(re-op2.re, im-op2.im);
        return res;
    }
    Complex operator*(Complex op2)
    {
        Complex res(re*op2.re - im*op2.im, re*op2.im + im*op2.re);
        return res;
    }
    Complex operator/(Complex op2)
    {
        double divider = op2.re*op2.re+op2.im*op2.im;
        Complex res((re*op2.re + im*op2.im)/divider,
                    (im*op2.re - re*op2.im)/divider);
        return res;
    }

    //--------------
    ~Complex() {}
};

int main()
{
    Complex aaa(3,4);
    Complex bbb;
    Complex ccc(5.6);

    puts("\nShow results:");
    Complex zz;

    zz=aaa + bbb;
    printf("Object: zz, Modulo: %f, argument: %f\n",zz.modulo(),zz.argument());

    zz=bbb - ccc;
    printf("Object: zz, Modulo: %f, argument: %f\n",zz.modulo(),zz.argument());

    zz=aaa*ccc;
    printf("Object: zz, Modulo: %f, argument: %f\n",zz.modulo(),zz.argument());

    zz=bbb/ccc;
    printf("Object: zz, Modulo: %f, argument: %f\n",zz.modulo(),zz.argument());

     return 0;
}









