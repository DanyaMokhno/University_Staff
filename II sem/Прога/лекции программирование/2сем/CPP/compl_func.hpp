#ifndef COMPL_FUNC_HPP_SENTRY
#define COMPL_FUNC_HPP_SENTRY

#include <math.h>
#include "compl_class.hpp"

Complex::Complex(double a_re, double a_im)
{
    re=a_re;
    im=a_im;
}
Complex::Complex() { re=0; im=0; }
Complex::Complex(double a) { re=a; im=0; }
double Complex::get_re() { return re; }
double Complex::get_im() { return im; }
double Complex::argument() { return atan2(im,re); }
double Complex::modulo() { return sqrt(re*re + im*im); }
void Complex::set_re(double param) { re=param; }
void Complex::set_im(double param) { im=param; }

#endif // COMPL_FUNC_HPP_SENTRY
