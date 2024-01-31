#include <stdio.h>
#define MAXLEN 8

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    /* Let's try to enter more than MAXLEN symbols */
    printf("Enter first string: ");
    scanf("%7s",s1);

    printf("Enter second string: ");
    scanf("%7s",s2);

    printf("Results: %s %s", s1, s2);
    return 0;
}
