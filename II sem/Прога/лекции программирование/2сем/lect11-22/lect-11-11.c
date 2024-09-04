#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* define structure */
struct student{
        char *name;
        char gender; /* 'm' or 'f' */
        int year_of_birth;
        char *spec;
        int year;
        char *group;
        float average;
};
/* define structured type */
typedef struct student studs;

/* function to clear array of string */
void clear_string_array(char **str, int n);

/* function to split string to array by separator */
char **simple_split(char *str, int length, char sep);

/* function to print header string without data */
void print_header();

/* function to output structure fields on console */
void struct_out(studs *str0);

/* function to create structure by array of strings*/
studs *struct_fill(char **str);

/* function to sort elements by rating */
void sort_rating(studs **str0, int n);

/* function to clear memory from structure */
void clear_structure(studs *str0);

int main()
{
    enum {maxlen=128};
    studs **stud0=NULL;
    int slen,i,n,count;
    char **s2=NULL;
    char s1[maxlen];
    char sep;
    FILE *df;

    printf("Enter your separator symbol: ");
    scanf("%c", &sep);

    df=fopen("struct-data-03.txt","r");
    if(df!=NULL)
    {
        n=0;
        while((fgets(s1,maxlen,df))!=NULL) n++;
        rewind(df);
        stud0=(studs**)malloc(n*sizeof(studs*));
        if(stud0!=NULL)
        {
            printf("Array address: %p\n", (void*)stud0); /* for debug */
            puts("Initial array:");
            print_header();
            for(i=0,count=0;i<n;i++,count++)
            {
                fgets(s1,maxlen,df);
                slen=strlen(s1);
                s1[slen-1]='\0';
                slen=strlen(s1);

                s2=simple_split(s1,slen,sep);
                if(s2!=NULL)
                {
                    stud0[i]=struct_fill(s2);
                    if(stud0[i]!=NULL) struct_out(stud0[i]);
                    else
                    {
                        puts("Structure not allocated!");
                        i=n;
                    }
                }
                else puts("Error at data reading!");
            }
        }
        else puts("No memory allocation!");
        fclose(df);

        if(stud0!=NULL)
        {
            puts("");
            puts("Sorted array:");
            print_header();
            sort_rating(stud0,n);
            for(i=0;i<count;i++)
            {
                struct_out(stud0[i]);
                clear_structure(stud0[i]);
            }
        }
        free(stud0);
        stud0=NULL;
    }
    else puts("File not found!");
    return 0;
}

/* ----------------------------------------- */
void clear_string_array(char **str, int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        free(str[i]);
        str[i]=NULL;
    }
    free(str);
    str=NULL;

}
/* ----------------------------------------- */
char **simple_split(char *str, int length, char sep)
{
    char **str_array=NULL;
    int i,j,k,m;
    int key,count;
    for(j=0,m=0;j<length;j++)
    {
        if(str[j]==sep) m++;
    }

    key=0;
    str_array=(char**)malloc((m+1)*sizeof(char*));
    if(str_array!=NULL)
    {
        for(i=0,count=0;i<=m;i++,count++)
        {
            str_array[i]=(char*)malloc(length*sizeof(char));
            if(str_array[i]!=NULL) key=1;
            else
            {
                key=0;
                i=m;
            }
        }
        if(key)
        {
            k=0;
            m=0;
            for(j=0;j<length;j++)
            {
                if(str[j]!=sep) str_array[m][j-k]=str[j];
                else
                {
                    str_array[m][j-k]='\0';
                    k=j+1;
                    m++;
                }
            }
        }
        else
        {
            clear_string_array(str_array,count);
        }
     }
     return str_array;
}
/* ----------------------------------------- */
void print_header()
{
    printf("|%20s |%6s|%6s |%10s |%6s |%6s |%5s|\n","fullname","gender","year","code","course","group","ball");
    printf("+---------------------+------+-------+-----------+-------+-------+-----+\n");
}
/* ----------------------------------------- */
void struct_out(studs *str0)
{
    printf("|%20s |   %c  |%6d |%10s |%6d |%6s |%5.3f|\n",
        str0->name,str0->gender,str0->year_of_birth,str0->spec,str0->year,str0->group,str0->average);
}
/* ----------------------------------------- */
studs *struct_fill(char **str)
{
    studs *str0=NULL;

    str0=(studs*)malloc(sizeof(studs));
    if(str0!=NULL)
    {
        str0->name=str[0];
        str0->gender=*str[1];
        str0->year_of_birth=atoi(str[2]);
        str0->spec=str[3];
        str0->year=atoi(str[4]);
        str0->group=str[5];
        str0->average=atof(str[6]);
    }
    return str0;
}
/* ----------------------------------------- */
void sort_rating(studs **str0, int n)
{
    studs *tmp_struct;
    int i,j;

    for(i=0;i<n;i=i+1)
    {
        tmp_struct=str0[i];
        for(j=i-1;(j>=0)&&((str0[j]->average)>(tmp_struct->average));j--)
            str0[j+1]=str0[j];
        str0[j+1]=tmp_struct;
     }
}
/* ----------------------------------------- */
void clear_structure(studs *str0)
{
    free(str0->name);
    free(str0->group);
    free(str0->spec);
    str0->name=NULL;
    str0->group=NULL;
    str0->spec=NULL;
    free(str0);
    str0=NULL;
}


