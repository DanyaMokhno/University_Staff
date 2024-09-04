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
void push(item **top, char *word, int len, int n);

item *pop(item **top);

item *peek(item *top);

int elem_count(item *top);

void clear_stack(item *top);

/* MAIN program */
int main()
{
    enum {maxlen=64};
    item *stack=NULL;
    item *st=NULL;
    char myword[maxlen];
    int slen,n,i;

    printf("How much elements? ");
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

        push(&stack,myword,slen,i+1);
        printf("%d %s %p\n",stack->id,stack->data,(void*)stack);
    }

    puts("\nEntering finished, POP last element");
    st=pop(&stack);
    printf("%d %s %p\n",st->id,st->data,(void*)st);
    if(st)
    {
        free(st);
        st=NULL;
    }
    puts("\nAnd now PEEK at top of stack");
    st=peek(stack);
    /* We need to check the presence of elements */
    if(st) printf("%d %s %p\n",st->id,st->data,(void*)st);
    else printf("%p\n",(void*)st);
    n=elem_count(stack);
    printf("Elements in stack: %d\n",n);

    /* Clearing stack */
    clear_stack(stack);
    return 0;
}

/* Function implementation */
void push(item **top, char *word, int len, int n)
{
    item *tmp=NULL;
    char *someword=NULL;

    tmp=(item*)malloc(sizeof(item));
    someword=(char*)malloc((len+1)*sizeof(char));

    if(tmp&&someword)
    {
        tmp->next=*top;
        strcpy(someword,word);
        tmp->data=someword;
        tmp->id=n;
        *top=tmp;
    }
}
/* ---------------------------------------------- */
item *pop(item **top)
{
    item *tmp=NULL;

    if(top)
    {
        tmp=*top;
        *top=(*top)->next;
    }
    return tmp;
}
/* ---------------------------------------------- */
item *peek(item *top)
{
    return top;
}
/* ---------------------------------------------- */
int elem_count(item *top)
{
    item *tmp;
    int i;

    i=0;
    if(top)
    {
        tmp=top;
        while(tmp)
        {
            tmp=tmp->next;
            i++;
        }
    }
    return i;
}
/* ---------------------------------------------- */
void clear_stack(item *top)
{
    item *tmp=NULL;

    while(top)
    {
        tmp=pop(&top);
        free(tmp);
        tmp=NULL;
    }
}
