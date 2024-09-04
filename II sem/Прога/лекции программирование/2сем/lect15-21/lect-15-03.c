#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* definition of node */
struct LNode
{
    int   id; /* unique value */
    char  *word;  /* data area */
    struct LNode *prev; /* link to previous node */
    struct LNode *next; /* link to next node */
};

struct LHead
{
    int cnt; /* counter of nodes */
    struct LNode *first; /* pointer to first element */
    struct LNode *last; /* pointer to last element */
};

typedef struct LHead Head; /* datatype for head */
typedef struct LNode Node; /* datatype for node */

Head *make_head() /* head initialization */
{
    Head *ph=NULL;

    ph=(Head*)malloc(sizeof(Head));
    if(ph!=NULL)
    {
        ph->cnt=0;
        ph->first=NULL;
        ph->last=NULL;
    }
    return ph;
}

Node *create_node2(char *new_word, int slen)
{
    Node *new_node=NULL;
    char *someword=NULL;

    new_node=(Node*)malloc(sizeof(Node));
    someword=(char*)malloc((slen+1)*sizeof(char));
    if(new_node&&someword)
    {
        strcpy(someword,new_word);
        new_node->id=1;
        new_node->word=someword;
        new_node->prev=NULL;
        new_node->next=NULL;
    }
    return new_node;
}

void add_first2(Head *my_head, Node *new_node)
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
        n=my_head->cnt;
        prev_node->next=new_node;
        new_node->prev=prev_node;
        my_head->last=new_node;
        new_node->id=n+1;
        my_head->cnt=n+1;
    }
}

void insert_after2(Head *my_head, Node *new_node, Node *current_node)
{
    int n;
    Node *q=NULL;

    if(my_head&&new_node&&current_node)
    {
        n=my_head->cnt;
        if(current_node->next==NULL)
        {
            current_node->next=new_node;
            new_node->prev=current_node;
            my_head->last=new_node;
        }
        else
        {
            q=current_node->next;
            new_node->next=q;
            new_node->prev=current_node;
            q->prev=new_node;
            current_node->next=new_node;

        }
        new_node->id=n+1;
        my_head->cnt=n+1;
    }
}

int main()
{
    enum {max_word_length=64};
    Head *p0;
    Node *p, *p1;
    Node *my_node=NULL;
    char my_word[max_word_length];
    int slen;

    p0=make_head();

    printf("Please enter some word: ");
    fgets(my_word,max_word_length,stdin);
    slen=strlen(my_word);
    my_word[slen-1]='\0';

    my_node=create_node2(my_word,slen);
    p=my_node;

    add_first2(p0,p);
    printf("%d %s\n",p->id, p->word);
    printf("Initial head: %p, %d\n",(void*)p0->first, p0->cnt);

    printf("Please enter next word: ");
    fgets(my_word,max_word_length,stdin);
    slen=strlen(my_word);
    my_word[slen-1]='\0';

    my_node=create_node2(my_word,slen);
    p1=my_node;

    add_last2(p0,p1,p);
    printf("%d %s\n",p1->id, p1->word);
    printf("Modified head: %p, %p, %d\n",(void*)p0->first, (void*)p0->last, p0->cnt);
    printf("\n --Press \"\\q\" for terminate input--\n\n");
    p=p0->first;
    /* p=p0->last; */

    while(strncmp(my_word,"\\q",2)!=0)
    {
        printf("Please enter next word: ");
        fgets(my_word,max_word_length,stdin);
        slen=strlen(my_word);
        my_word[slen-1]='\0';

        if(strncmp(my_word,"\\q",2)!=0)
        {
            my_node=create_node2(my_word,slen);
            insert_after2(p0,my_node,p);
            p=my_node;
            printf("Address: %p, data: %d %s\n",(void*)p, p->id, p->word);
        }
    }
    printf("\n -- Intput terminated. Your data are: --- \n");

    p=p0->first;
    while(p)
    {
       p1=p->next;;
       printf("Address: %p, data: %d %s\n",(void*)p, p->id, p->word);
       free(p);
       p=p1;
    }

    free(p0);

    return 0;
}

