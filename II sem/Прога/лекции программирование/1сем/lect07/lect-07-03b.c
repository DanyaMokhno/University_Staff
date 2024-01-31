#include <stdio.h>
#define MAXLEN 8

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    int n1, n2;
    /* Let's try to enter more than MAXLEN symbols */
    printf("Enter first string: ");
    scanf("%7[^\n]",s1);

    printf("Enter second string: ");
    scanf("%7[^\n]",s2);

    n1=printf("%s", s1);
    n2=printf("%s", s2);
    puts("\nResults:");
    printf("String %s has %d symbols\n", s1, n1);
    printf("String %s has %d symbols\n", s2, n2);
    return 0;
}
