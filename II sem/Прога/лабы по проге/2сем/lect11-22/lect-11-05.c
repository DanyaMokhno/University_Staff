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

/* function to sort array of structures by numeric field
* (insertion method)                                    */
void sort_rating(struct student *str0, int n);

/* function to free fields in heap */
void mem_clear(struct student str0);

/* function to output structure fields on console */
void struct_out(struct student str0);

int main()
{
    studs *st1=NULL;
    enum {maxlen=128};
    int slen,i,count,n;
    int len1,len2,len3;
    char **s2=NULL;
    char s1[maxlen];
    char sep;
    FILE *df;

    df=fopen("struct-data-03.txt","r");
    if(df!=NULL)
    {
        n=0;
        count=0;
        while((fgets(s1,maxlen,df))!=NULL) n++;
        rewind(df);

        st1=(studs*)malloc(n*sizeof(studs));
        if(st1!=NULL)
        {
        /* Reading data from file and filling structures */
            sep=';';
            for(i=0;i<n;i++)
            {
                fgets(s1,maxlen,df);
                slen=strlen(s1);
                s1[slen-1]='\0';
                slen=strlen(s1);

                s2=simple_split(s1,slen,sep);
                if(s2!=NULL)
                {
                    len1=strlen(s2[0]);
                    len2=strlen(s2[3]);
                    len3=strlen(s2[5]);

                    st1[i].name=(char*)malloc((len1+1)*sizeof(char));
                    st1[i].spec=(char*)malloc((len2+1)*sizeof(char));
                    st1[i].group=(char*)malloc((len3+1)*sizeof(char));

                    if((st1[i].name!=NULL)&&(st1[i].spec!=NULL)&&(st1[i].group!=NULL))
                    {
                        strcpy(st1[i].name,s2[0]);
                        st1[i].gender=s2[1][0];
                        st1[i].year_of_birth=atoi(s2[2]);
                        strcpy(st1[i].spec,s2[3]);
                        st1[i].year=atoi(s2[4]);
                        strcpy(st1[i].group,s2[5]);
                        st1[i].average=atof(s2[6]);

                        count++;
                        clear_string_array(s2,7);
                    }
                    else
                    {
                        i=n;
                        puts("Out if memory! Program terminated");
                        clear_string_array(s2,7);
                    }
                }
            }
        }
        else puts("Error at memory allocation!");
        fclose(df);

        if(count==n)
        {
            puts("Initial array:");
            print_header();
            for(i=0;i<n;i++) struct_out(st1[i]);

            sort_rating(st1,n);

            puts("\nSorted array:");
            print_header();
            for(i=0;i<n;i++) struct_out(st1[i]);

            for(i=0;i<n;i++) mem_clear(st1[i]);
            free(st1);
            st1=NULL;
        }
        else
        {
            for(i=0;i<count;i++) mem_clear(st1[i]);
            if(st1!=NULL)
            {
                free(st1);
                st1=NULL;
            }

            puts("Sorry, processing not possible!");
        }
    }
    else perror("Data error!");
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
void mem_clear(struct student str0)
{

    free(str0.name);
    free(str0.spec);
    free(str0.group);
    str0.name=NULL;
    str0.spec=NULL;
    str0.group=NULL;
}
/* ----------------------------------------- */
void struct_out(struct student str0)
{
    printf("|%20s |   %c  |%6d |%10s |%6d |%6s |%5.3f|\n",
        str0.name,str0.gender,str0.year_of_birth,str0.spec,str0.year,str0.group,str0.average);
}
/* ----------------------------------------- */
void sort_rating(struct student *str0, int n)
{
    struct student tmp_struct;
    int i,j;

    for(i=0;i<n;i++)
    {
        tmp_struct=str0[i];
        for(j=i-1;(j>=0)&&(str0[j].average>tmp_struct.average);j--) str0[j+1]=str0[j];
        str0[j+1]=tmp_struct;
    }
}


