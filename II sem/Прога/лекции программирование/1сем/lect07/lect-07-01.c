#include <stdio.h>
#define MAXLEN 80

int main()
{
    char s1[MAXLEN]="\tHello \nWorld!";

    puts(s1);
    puts("This is string literal");
    printf("Hello string: %*s\n",30,s1);
    printf("%02x %02x\n",s1[0],s1[7]);
    return 0;
}
