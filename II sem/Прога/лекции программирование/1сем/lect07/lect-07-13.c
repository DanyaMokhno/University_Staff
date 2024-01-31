#include <stdio.h>

int my_isdigit(char c)
{
    int flag;

    if(((int)c>=48)&&((int)c<=57)) flag=1;
    else flag=0;

    return flag;
}

int main()
{
    char c0;
    int key;

    printf("Enter symbol to test: ");
    c0=getchar();
    key=my_isdigit(c0);
    if(key) puts("This is digit!");
    else puts("This is NOT digit!");

    return 0;
}

