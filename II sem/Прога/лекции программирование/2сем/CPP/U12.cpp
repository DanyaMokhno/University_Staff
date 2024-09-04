#include <stdio.h>
#include <math.h>
// Adding constructor to convert

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
    ~Complex() {}; // destructor do nothing
};

void print_re(Complex param)
{
    printf("Real part of object: %f\n", param.get_re());
}

int main()
{
    enum {maxlen=32};
    char s0[32];
    int n;

    printf("Your value: ");
    fgets(s0,maxlen,stdin);
    n=atoi(s0);

    Complex aaa(n);
    print_re(aaa);
    Complex bbb(3,4);
    print_re(bbb);
    print_re(2.5);

     return 0;
}







