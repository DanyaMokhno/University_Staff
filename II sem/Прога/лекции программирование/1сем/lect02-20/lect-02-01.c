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

    if(key=='*') res=x*2;
    else if(key=='/') res=x/2;
    else if(key=='+') res=x+2;
    else if(key=='-') res=x-2;
    else puts("Do nothing!");

    printf("%.2lf\n", res);
    return 0;
}
