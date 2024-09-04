#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* definition of node */
struct LNode
{
    int   id; /* unique value */
    char  *word;  /* data area */
    struct Node  *next; /* link to next node */
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

Node *create_node(char *new_word, int slen) /* node initialization */
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
        new_node->next = NULL;           /* next node is absent */
    }
    return new_node;  /* return of node address */
}

void add_first(Head *my_head, Node *new_node) /* link head to first node */
{
    my_head->first = new_node;
    my_head->last = new_node;
    my_head->cnt++;
}

int main()
{
    enum {max_word_length=64};
    Head *p0;
    Node *my_node = NULL;
    Node *p;
    char my_word[max_word_length];
    int slen;

    p0=make_head();

    printf("Please enter some word: ");
    fgets(my_word,max_word_length,stdin);
    slen=strlen(my_word);
    my_word[slen-1]='\0';

    my_node=create_node(my_word,slen);
    p=my_node;

    if(p0&&p)
    {
        add_first(p0,p);

        printf("%d %s\n",p->id, p->word);
        printf("Initial Head: %p %d\n",(void*)p0->first, p0->cnt);

        free(p);
        free(p0);
    }
    else puts("Nothing to do!");
    return 0;
}

