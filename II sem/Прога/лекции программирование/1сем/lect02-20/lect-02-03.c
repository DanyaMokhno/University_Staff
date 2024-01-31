#include <stdio.h>

int main()
{
    int n;
    char c;

    n=0;
    puts("Please enter symbols one by one...");

    while((c=getchar())!='\n') n=n+1;

    printf("%d symbols was entered\n", n);
    return 0;
}
