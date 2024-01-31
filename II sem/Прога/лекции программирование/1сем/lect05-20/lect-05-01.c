/* Calculation of hypotenuse on rectangular triangle */
#include <stdio.h>
#include <math.h>

double hypot2(double x, double y)
{
    return sqrt(x*x+y*y);
}

int main()
{
    int a,b,n;

    puts("Enter sizes A and B:");
    n=scanf("%i %i",&a,&b);
    if(n==2)
    {
        printf("Result: %lf\n", hypot2(a,b));
        getchar();
        puts("Press ENTER when ready");
        getchar();
    }
    else puts("Incorrect data, please try again...");
    return 0;
}

