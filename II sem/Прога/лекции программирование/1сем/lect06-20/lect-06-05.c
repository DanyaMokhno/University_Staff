#include <stdio.h>
/* Function to calculate FACTORIAL recursively */
long factorial(int n)
{
    long f;
    if (n<0) f=0;
    else if(n<=1) f=1;
    else f=n*factorial(n-1);
    return f;
}

int main()
{
    int i;
    long fact;

    printf("Enter value: ");
    scanf("%d", &i);
    fact=factorial(i);
    printf("%d! = %ld\n",i,fact);
    return 0;
}
