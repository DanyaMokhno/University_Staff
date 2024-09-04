#ifndef COMPL_CLASS_HPP_SENTRY
#define COMPL_CLASS_HPP_SENTRY

class Complex {
private:
    double re, im;
public:
    Complex(double a_re, double a_im);
    Complex();
    Complex(double a);
    double get_re();
    double get_im();
    double argument();
    double modulo();
    void set_re(double param);
    void set_im(double param);
    ~Complex() {}; // destructor do nothing
};

#endif // COMPL_CLASS_HPP_SENTRY


