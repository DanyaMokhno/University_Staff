#include <stdio.h>
/* Function to calculate x^n recursively       */
/* x is a base (real), n is a factor (integer) */
double stepen(double a, int n)
{
    double st;
    if(n==0) st=1;
    else if(n<0) st=1/stepen(a,-n);
    else st=a*stepen(a,n-1);
    return st;
}

int main()
{
    int n;
    double s,x;

    printf("Base x= ");
    scanf("%lf",&x);
    printf("Factor n= ");
    scanf("%d",&n);
    s=stepen(x,n);
    printf("Result: %.5f\n",s);
    return 0 ;
}
