#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLEN 128
#define N 4

/* function to clear array of string */
void ClearStringArray(char **str, int n);

/* function to split string to array by separator */
char **simple_split(char *str, int length, char sep);

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

int main()
{
    studs st1[N];
    int slen,i,count;
    int len1,len2,len3;
    char **s2=NULL;
    char s1[MAXLEN];
    char sep;
    FILE *df;

    df=fopen("struct-data-03.txt","r");
    if(df!=NULL)
    {
/*Reading data from file and filling structures */
        sep=';';
        for(i=0,count=0;i<N;i++)
        {
            fgets(s1,MAXLEN,df);
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
                    st1[i].gender=*s2[1];
                    st1[i].year_of_birth=atoi(s2[2]);
                    strcpy(st1[i].spec,s2[3]);
                    st1[i].year=atoi(s2[4]);
                    strcpy(st1[i].group,s2[5]);
                    st1[i].average=atof(s2[6]);
                    count++;

                    ClearStringArray(s2,7);
                }
                else
                {
                    i=N;
                    puts("Out if memory! Program terminated");
                }

            }
        }
        fclose(df);

        if(count==N)
        {
            printf("|%20s |%6s|%6s |%10s |%6s |%6s |%5s|\n","fullname","gender","year","code","course","group","ball");
            printf("+---------------------+------+-------+-----------+-------+-------+-----+\n");

            for(i=0;i<N;i++)
            {
                printf("|%20s |   %c  |%6d |%10s |%6d |%6s |%5.3f|\n",
                    st1[i].name,st1[i].gender,st1[i].year_of_birth,st1[i].spec,st1[i].year,st1[i].group,st1[i].average);
            }

            for(i=0;i<N;i++)
            {
                free(st1[i].name);
                free(st1[i].spec);
                free(st1[i].group);
                st1[i].name=NULL;
                st1[i].spec=NULL;
                st1[i].group=NULL;
            }
        }
        else
        {
            for(i=0;i<count;i++)
            {
                free(st1[i].name);
                free(st1[i].spec);
                free(st1[i].group);
                st1[i].name=NULL;
                st1[i].spec=NULL;
                st1[i].group=NULL;
            }
            puts("Sorry, processing not possible!");
        }

    }
    else perror("Data error!");
    return 0;
}
/* ----------------------------------------- */
void ClearStringArray(char **str, int n)
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
            ClearStringArray(str_array,count);
        }
     }
     return str_array;
}
