#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 80

int main()
{
    char *s1=NULL;
    int i,slen;

    s1=(char*)malloc(MAXLEN*sizeof(char));
    if(s1!=NULL)
    {
        printf("Enter your string: ");
        fgets(s1,MAXLEN,stdin);
        slen=strlen(s1); /* string after fgets() */

        for(i=0;i<slen;i++) printf("%d ",s1[i]);
        s1[slen-1]='\0'; /* deleting \n at end of string */

        slen=strlen(s1); /* for pure string */
        printf("\nString \"%s\" has %d symbols\n",s1,slen);

        free(s1);
        s1=NULL;
    }
    else puts("Error at memory allocation!");
    return 0;
}
