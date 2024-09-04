#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* Type definitions */
struct elem
{
    int id;
    char *data;
    struct elem *prev;
    struct elem *next;
};

typedef struct elem item;

/* Function prototypes */
void put(item **qbegin, item **qend, char *word, int len, int n);

item *get(item **qbegin, item **qend);

item *view(item *qbegin);

int elem_count(item *qbegin);

void clear_queue(item *qbegin, item *qend);

/* MAIN program */
int main()
{
    enum {maxlen=64};
    item *qb=NULL;
    item *qe=NULL;
    item *q0=NULL;
    char myword[maxlen];
    int slen,n,i;

    printf("How much elements (>0)? ");
    fgets(myword,maxlen,stdin);
    slen=strlen(myword);
    myword[slen-1]='\0';
    n=atoi(myword);
    for(i=0;i<n;i++) /* Cycle to adding elements in stack */
    {
        printf("Your word: ");
        fgets(myword,maxlen,stdin);
        slen=strlen(myword);
        myword[slen-1]='\0';

        put(&qb,&qe,myword,slen,i+1);
        printf("%d %s %p\n",qe->id,qe->data,(void*)qe);
    }

    puts("\nEntering finished, GET last element");
    q0=get(&qb,&qe);
    printf("%d %s %p\n",q0->id,q0->data,(void*)q0);
    if(q0)
    {
        free(q0);
        q0=NULL;
    }
    puts("\nAnd now VIEW at begin of Queue");
    q0=view(qb);
    /* We need to check the presence of elements */
    if(q0) printf("%d %s %p\n",q0->id,q0->data,(void*)q0);
    else printf("%p\n",(void*)q0);
    n=elem_count(qe);
    printf("Elements in Queue: %d\n",n);
    /* Clearing Queue */
    clear_queue(qb,qe);
    return 0;
}

/* Function implementation */
void put(item **qbegin, item **qend, char *word, int len, int n)
{
    item *tmp=NULL;
    char *someword=NULL;

    tmp=(item*)malloc(sizeof(item));
    someword=(char*)malloc((len+1)*sizeof(char));

    if(tmp&&someword)
    {
        strcpy(someword,word);
        tmp->data=someword;
        tmp->id=n;
        if(!(*qbegin)) /* Queue is empty */
        {
            *qbegin=tmp;
            (*qbegin)->next=NULL;
            (*qbegin)->prev=NULL;
            *qend=tmp;
            (*qend)->next=NULL;
            (*qend)->prev=NULL;
        }
        else
        {
            tmp->next=*qend;
            (*qend)->prev=tmp;
            *qend=tmp;
            if(!((*qbegin)->prev)) (*qbegin)->prev=tmp;
        }
    }
}
/* ---------------------------------------------- */
item *get(item **qbegin, item **qend)
{
    item *tmp=NULL;

    if(*qbegin) /* Queue is not empty */
    {
        tmp=*qbegin;
        *qbegin=(*qbegin)->prev;
        if(*qbegin) /* Queue is not empty now */
        {
            if((*qbegin)->next) (*qbegin)->next=NULL;
        }
        else *qend=NULL;
    }
    return tmp;
}
/* ---------------------------------------------- */
item *view(item *qbegin)
{
    return qbegin;
}
/* ---------------------------------------------- */
int elem_count(item *qend)
{
    item *tmp;
    int i;

    i=0;
    if(qend) /* Queue is not empty */
    {
        tmp=qend;
        while(tmp)
        {
            tmp=tmp->next;
            i++;
        }
    }
    return i;
}
/* ---------------------------------------------- */
void clear_queue(item *qbegin, item *qend)
{
    item *tmp=NULL;
    while(qbegin) /* Queue is not empty */
    {
       tmp=get(&qbegin,&qend);
       free(tmp);
       tmp=NULL;
    }
}
