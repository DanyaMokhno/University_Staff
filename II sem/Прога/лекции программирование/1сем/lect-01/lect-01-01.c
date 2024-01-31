#include <stdio.h>

int main()
{
    int x, y,n;

    puts("Calculation of Y=X+5");
    puts("Enter value of X: ");
    scanf("%i", &x);
    y=x+5;
    n=printf("Result: Y=%i\n", y);
    printf("%d\n",n);
    return 0;
}
