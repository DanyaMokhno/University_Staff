#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct LNode {
    int   id;
    char  *word;  /* data area */
    struct LNode  *next;     /* link to next node */
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

Node *create_node(char *new_word, int slen) /* node initialization */
{
    Node *new_node=NULL; /* pointer to new node */
    char *word;

    new_node = (Node*)malloc(sizeof(Node));
    word=(char*)malloc((slen+1)*sizeof(char));
    if(new_node&&word)
    {
        new_node->id = 1;    /* setting node ID to 1 */
        memcpy(word,new_word,slen+1);
        new_node->word=word;
        new_node->next = NULL;           /* next node is absent */
    }
    return new_node;  /* return of node address */
}

void add_first(Head *my_head, Node *new_node)
{
    if(my_head&&new_node)
    {
        my_head->first = new_node;
        my_head->last = new_node;
        my_head->cnt++;
    }
}

void add_last(Head *my_head, Node *new_node, Node *prev_node)
{
    int n;

    if(my_head&&new_node&&prev_node)
    {
        n=my_head->cnt+1;
        prev_node->next=new_node;
        new_node->id=n;
        my_head->last=new_node;
        my_head->cnt=n;
    }
}

void insert_after(Head *my_head, Node *new_node, Node *current_node)
{
    int n;
    if(my_head&&new_node&&current_node)
    {
        n=my_head->cnt+1;
        if(current_node->next==NULL)
        {
            current_node->next=new_node;
            my_head->last=new_node;
        }
        else
        {
            new_node->next = current_node->next;
            current_node->next=new_node;
        }
        new_node->id=n;
        my_head->cnt=n;
    }
}

void insert_before(Head *my_head, Node *new_node, Node *current_node)
{
    Node *q=NULL;
    Node *q1=NULL;
    int n;

    if(my_head&&new_node&&current_node)
    {
        if(my_head->first==current_node)
        {
            n=my_head->cnt+1;
            new_node->id=n;
            new_node->next=current_node;
            my_head->first=new_node;
            my_head->cnt=n;
        }
        else
        {
            q=my_head->first;
            while(q!=NULL)
            {
                if(q->next==current_node)
                {
                    q1=q;
                    insert_after(my_head,new_node,q1);
                    q=NULL;
                }
                else q=q->next;
            }
        }
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

    p=create_node(my_word,slen);
    /*p=my_node; saving node address */

    add_first(p0,p);

    printf("%d %s\n",p->id, p->word);
    printf("Initial Head: %p %d\n",(void*)p0->first, p0->cnt);

    p=p0->first; /* pointer to insert before */
    /* You can use add_last() function and insert
    elements before last element */
    /*printf("%s: ","Please enter some word");
    fgets(my_word,max_word_length,stdin);
    slen=strlen(my_word);
    my_word[slen-1]='\0';
    p1=create_node(my_word,slen);
    add_last(p0,p1,p);
    p=p0->last; */

    printf("\n--Press \"\\q\" for terminate input--\n\n");
    while(strncmp(my_word,"\\q",2)!=0)
    {
        printf("%s: ","Please enter next word");
        fgets(my_word,max_word_length,stdin);
        slen=strlen(my_word);
        my_word[slen-1]='\0';

        if(strncmp(my_word,"\\q",2)!=0)
        {
             my_node=create_node(my_word,slen);
             insert_before(p0, my_node, p);
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


