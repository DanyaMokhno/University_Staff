#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LNode
{
    int   id; /* unique value */
    char  *word;  /* data area */
    struct LNode *prev; /* link to previous node */
    struct LNode *next; /* link to next node */
};

struct LHead {
    int cnt;
    struct LNode *first;
    struct LNode *last;
};

typedef struct LHead Head;
typedef struct LNode Node; /* datatype for pointer to node */

Head *make_head()
{
    Head *ph=NULL;

    ph=(Head*)malloc(sizeof(Head));
    if(ph)
    {
        ph->cnt=0;
        ph->first=NULL;
        ph->last=NULL;
    }
    return ph;
}

Node *create_node2(char *new_word, int slen) /* node initialization */
{
   Node *new_node=NULL; /* pointer to new node */
   char *someword=NULL;

    new_node = (Node*)malloc(sizeof(Node));
    someword=(char*)malloc((slen+1)*sizeof(char));
    if(new_node&&someword)
    {
        strcpy(someword,new_word);
        new_node->id = 1;             /* setting node ID to 1 */
        new_node->word=someword;
        new_node->prev = NULL;       /* previous node is absent */
        new_node->next = NULL;       /*     next node is absent */
    }
    return new_node;  /* return of node address */
}

void add_first2(Head *my_head, Node *new_node) /* link head to first node */
{
    my_head->first = new_node;
    my_head->last = new_node;
    my_head->cnt++;
}

void add_last2(Head *my_head, Node *new_node, Node *prev_node)
{
    int n;

    if(my_head&&new_node&&prev_node)
    {
        n=my_head->cnt+1;
        prev_node->next=new_node;
        new_node->prev=prev_node;
        my_head->last=new_node;
        new_node->id=n;
        my_head->cnt=n;
    }
}

void insert_after2(Head *my_head, Node *new_node, Node *current_node)
{
    int n;
    if(my_head&&new_node&&current_node)
    {
        n=my_head->cnt+1;
        if(current_node->next==NULL)
        {
            current_node->next=new_node;
            new_node->prev=current_node;
            my_head->last=new_node;
        }
        else
        {
            new_node->next = current_node->next;
            current_node->next=new_node;
            new_node->prev=current_node;
        }
        new_node->id=n;
        my_head->cnt=n;
    }
}

void insert_before2(Head *my_head, Node *new_node, Node *current_node)
{
    Node *q=NULL;
    int n;

    if(my_head&&new_node&&current_node)
    {
        if(my_head->first==current_node)
        {
            new_node->next=current_node;
            current_node->prev=new_node;
            my_head->first=new_node;

        }
        else
        {
            q=current_node->prev;
            new_node->next=current_node;
            new_node->prev=q;
            q->next=new_node;
            current_node->prev=new_node;
        }
        n=my_head->cnt+1;
        new_node->id=n;
        my_head->cnt=n;
    }
}

int main()
{
    enum {max_word_length=64};
    Head *p0;
    Node *p,*p1,*my_node=NULL;
    char my_word[max_word_length];
    int slen;

    p0=make_head();

    printf("%s: ","Please enter some word");
    fgets(my_word,max_word_length,stdin);
    slen=strlen(my_word);
    my_word[slen-1]='\0';

    p1=create_node2(my_word,slen); /* saving node address */

    add_first2(p0,p1);

    printf("%d %s\n",p1->id, p1->word);
    printf("Initial Head: %p %d\n",(void*)p0->first, p0->cnt);

    p=p0->first; /* pointer to insert before */
    /* You can use add_last2() function and insert
    elements before last element */
/*    printf("%s: ","Please enter some word");
    fgets(my_word,max_word_length,stdin);
    slen=strlen(my_word);
    my_word[slen-1]='\0';
    p1=create_node2(my_word,slen);
    add_last2(p0,p1,p);
    p=p0->last;
*/
    printf("\n--Press \"\\q\" for terminate input--\n\n");
    while(strncmp(my_word,"\\q",2)!=0)
    {
        printf("%s: ","Please enter next word");
        fgets(my_word,max_word_length,stdin);
        slen=strlen(my_word);
        my_word[slen-1]='\0';

        if(strncmp(my_word,"\\q",2)!=0)
        {
             my_node=create_node2(my_word,slen);
             insert_before2(p0, my_node, p);
             p=my_node;
             printf("Address: %p, data: %d %s\n",(void*)p, p->id, p->word);
        }
    }
    printf("\n--Input teminated. Your data are:--\n");

    p=p0->first;
    while(p!=NULL)
    {
        printf("Address: %p, data: %d %s\n",(void*)p, p->id, p->word);
        p=p->next;
    }
    printf("Modified Head: %p %p %d\n",(void*)p0->first, (void*)p0->last, p0->cnt);

    p=p0->first;
    while(p!=NULL)
    {
        p1=p->next;
        free(p);
        p=p1;
    }
    free(p0);

    return 0;
}


