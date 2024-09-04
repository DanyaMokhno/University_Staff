#include <stdio.h>

int main()
{
    enum lg0 {c, cpp, pascal, ada};
    enum lg1 {python=11, perl, php, js};
    enum lg0 x;
    enum lg1 y;
    int z;

    x=cpp;
    printf("Current language= %d\n", x);

    z=x+123;
    printf("Current value= %d\n", z);
    if(x==cpp) printf("Current language is cpp\n");

    y=perl;
    printf("Value of y: %d\n", y);
    return 0;
}


