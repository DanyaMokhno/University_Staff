#include <stdio.h>
#include <string.h>
#define MAXLEN 80

int main()
{
    char s1[MAXLEN], s2[MAXLEN];
    int i,n1,n2;

    printf("Enter first string: ");
    fgets(s1,MAXLEN,stdin);

    printf("Enter second string: ");
    fgets(s2,MAXLEN,stdin);

    n1=strlen(s1);
    n2=strlen(s2);
    s1[n1-1]='\0';
    s2[n2-1]='\0';
    puts("\nResults:");
    printf("String %s has %d symbols\n", s1, n1);
    printf("String %s has %d symbols\n", s2, n2);

    for(i=0;i<n1;i++) printf("%02x ",s1[i]);
    puts("");
    return 0;
}
