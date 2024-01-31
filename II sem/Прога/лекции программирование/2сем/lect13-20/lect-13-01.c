#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* definition of node */
struct LNode
{
	char data[32];
	struct LNode *next;
};

typedef struct LNode LN;

int main()
{
    LN *LHead=NULL; /* define and init head */
    LN *p=NULL;

    p=(LN*)malloc(sizeof(LN));
    if(p!=NULL)
    {
        strcpy(p->data,"dataword"); /* init node */
        p->next=NULL;
        LHead=p; /* make link head to node */

        printf("%p\n", (void*)LHead);
        free(p);
    }
    return 0;
}
