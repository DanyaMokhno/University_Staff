#include <stdio.h>

int main()
{
    double x, res;
    char key;

    printf("Enter initial value: ");
    scanf("%lf", &x);
    res=x;
    printf("Your operation? ");
    getchar();
    scanf("%c", &key);

    switch(key)
    {
        case '*': res=x*2;
            break;
        case '/': res=x/2;
            break;
        case '+': res=x+2;
            break;
        case '-': res=x-2;
            break;
        default: puts("Do nothing!");
    }
    printf("%.2lf\n", res);
    return 0;
}
