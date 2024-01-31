#include <stdio.h>
/* Function to calculate n-th Fibonacci value recursively */
long fibon(unsigned n)
{
    long f;

    if((n==0)||(n==1)) f=n;
    else f=fibon(n-1)+fibon(n-2);
    return f;
}

int main()
{
    int n;
    long f;
    printf("Enter desired number: ");
    scanf("%d",&n);
    f=fibon(n);
    printf("Fibonachi value number %d: %ld\n",n,f);
    return 0 ;
}
