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

    my_node=create_node2(my_word,slen);
    p1=my_node; /* saving node address */

    printf("%s: ","Please enter some word");
    fgets(my_word,max_word_length,stdin);
    slen=strlen(my_word);
    my_word[slen-1]='\0';

    p=create_node2(my_word,slen);

    if(p0&&p&&p1)
    {
        add_first2(p0,p1);

        printf("%d %s\n",p1->id, p1->word);
        printf("Initial Head: %p %d\n",(void*)p0->first, p0->cnt);

        add_last2(p0,p,p1);
        printf("%d %s\n",p->id, p->word);
        printf("Modified Head: %p %p %d\n",(void*)p0->first, (void*)p0->last, p0->cnt);

        free(p);
        free(p1);
        free(p0);
    }
    else puts("Nothing to do!!");

    return 0;
}
