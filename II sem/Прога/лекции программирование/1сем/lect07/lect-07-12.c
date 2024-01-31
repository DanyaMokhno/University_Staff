#include <stdio.h>

int my_isalpha(char c)
{
    int flag;

    flag=0;
    if(((int)c>=65)&&((int)c<=90)) flag++;
    if(((int)c>=97)&&((int)c<=122)) flag++;

    return flag;
}

int main()
{
    char c0;
    int key;

    printf("Enter symbol to test: ");
    c0=getchar();
    key=my_isalpha(c0);
    if(key) puts("This is letter!");
    else puts("This is NOT letter!");

    return 0;
}
