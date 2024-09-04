#include <stdio.h>
#include <math.h>

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
    Complex(double a) { re=a; im=0; }
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
    enum {maxlen=32};
    char s0[32];
    double a,b;
    Complex *aaa; // array of objects!!
    int i;

    aaa = new Complex[2]; // array initialization!! (call of constructor!!)
    for(i=0; i<2; i++)
    {

        printf("Real part: ");
        fgets(s0,maxlen,stdin);
        a=atof(s0);

        printf("Imagine part: ");
        fgets(s0,maxlen,stdin);
        b=atof(s0);

        aaa[i].set_re(a);
        aaa[i].set_im(b);
    }

    puts("\nShow results:");
    Complex zz;

    zz=aaa[0].operator+(aaa[1]);
    printf("Object: zz, Modulo: %f, argument: %f\n",zz.modulo(),zz.argument());

    zz=aaa[0]-aaa[1];
    printf("Object: zz, Modulo: %f, argument: %f\n",zz.modulo(),zz.argument());

    zz=aaa[0]*aaa[1];
    printf("Object: zz, Modulo: %f, argument: %f\n",zz.modulo(),zz.argument());

    zz=aaa[0]/aaa[1];
    printf("Object: zz, Modulo: %f, argument: %f\n",zz.modulo(),zz.argument());

    delete [] aaa;

     return 0;
}








