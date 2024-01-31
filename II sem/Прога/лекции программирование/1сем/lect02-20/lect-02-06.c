#include <stdio.h>

int main()
{
    int n;
    char c;

    puts("Please enter symbols one by one...");

    for(n=0;(c=getchar())!='\n';n=n+1);

    printf("%d symbols was entered\n", n);
    return 0;
}
