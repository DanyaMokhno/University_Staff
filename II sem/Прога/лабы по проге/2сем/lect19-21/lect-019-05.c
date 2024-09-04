#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Type definitions */
struct elem
{
    int id;
    char *data;
    struct elem *next;
};

typedef struct elem item;

/* Function prototypes */
item *put(int n);

void get(item *qb);

int elem_count(item *qb);

/* MAIN program */
int main(int argvc, char **argv)
{
    item *q=NULL;
    int n;
    n=atoi(argv[1]);

    q=put(n);
    puts("\nEntering finished");
    printf("Name of program: %s\n",argv[0]);
    printf("Number of arguments: %d\n",argvc);
    n=elem_count(q);
    printf("Elements in queue: %d\n",n);
    puts("\nGet all elements:");
    get(q);
    return 0;
}

/* Function implementation */
item *put(int n)
{
    enum {maxlen=64};
    item *tmp=NULL;
    char *someword=NULL;
    char myword[maxlen];
    int len;

    printf("Your word: ");
    fgets(myword,maxlen,stdin);
    len=strlen(myword);
    myword[len-1]='\0';
    n++;
    tmp=(item*)malloc(sizeof(item));
    someword=(char*)malloc((len+1)*sizeof(char));

    if((len-1)==0)
    {
        free(tmp);
        tmp=NULL;
    }
    else
    {
        if(tmp&&someword)
        {
            strcpy(someword,myword);
            tmp->data=someword;
            tmp->id=n;
            tmp->next=put(n);
        }
    }
    return tmp;
}
// ----------------------------------------------
void get(item *qb)
{

    if(qb==NULL) printf("End of queue!\n");
    else
    {
        printf("id: %d \tword: %s\n",qb->id,qb->data);
        get(qb->next);
        free(qb);
        qb=NULL;
    }
}
// ----------------------------------------------
int elem_count(item *qb)
{
    item *tmp;
    int i;

    i=0;
    if(qb)
    {
        tmp=qb;
        while(tmp)
        {
            tmp=tmp->next;
            i++;
        }
    }
    return i;
}

