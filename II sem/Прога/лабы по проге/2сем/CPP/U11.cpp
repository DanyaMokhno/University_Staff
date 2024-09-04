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
    double get_re() { return re; }
    double get_im() { return im; }
    double argument() { return atan2(im,re); }
    double modulo() { return sqrt(re*re + im*im); }
    void set_re(double param) { re=param; }
    void set_im(double param) { im=param; }
    ~Complex() {}; // destructor do nothing
};

int main()
{
    enum {maxlen=32};
    char s0[32];
    double a,b,m;
    Complex *aaa; // array of objects!!
    int i,n;

    printf("How many objects? : ");
    fgets(s0,maxlen,stdin);
    n=atoi(s0);

    aaa = new Complex[n]; // array initialization!! (call of constructor!!)
    for(i=0; i<n; i++)
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
    for(i=0; i<n; i++)
    {
        m=aaa[i].modulo();
        a=aaa[i].argument();
        printf("Object: %d, Modulo: %f, argument: %f\n",i,m,a);
    }

    delete [] aaa;

     return 0;
}






