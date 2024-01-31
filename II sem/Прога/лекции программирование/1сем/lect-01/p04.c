#include <stdio.h>

int main()
{
    int i,k;

    puts("Postfix form");
    i=0;
    while(i<5)
    {
        k=i++;
        printf("%d\n",k);
    }
    puts("Prefix form");
    i=0;
    while(i<5)
    {
        k=++i;
        printf("%d\n",k);
    }
    return 0;
}
