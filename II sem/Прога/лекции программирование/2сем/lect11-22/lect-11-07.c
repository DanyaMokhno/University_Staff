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
void struct_out(studs *str0); /* !Modified !! */

int main()
{
    studs *stud0=NULL;
    enum {maxlen=128};
    int slen;
    char **s2=NULL;
    char s1[maxlen];
    char sep;
    FILE *df;

    printf("Enter your separator symbol: ");
    scanf("%c", &sep);

    df=fopen("struct-data-03.txt","r");
    if(df!=NULL)
    {
        fgets(s1,maxlen,df);
        fclose(df);

        printf("\nSource string: %s\n",s1);
        slen=strlen(s1);
        s1[slen-1]='\0';
        slen=strlen(s1);

        s2=simple_split(s1,slen,sep);
        if(s2!=NULL)
        {
            stud0=(studs*)malloc(sizeof(studs));
            if(stud0!=NULL)
            {
               /* Filling fields of structure by array of strings s2*/
                (*stud0).name=s2[0];
                (*stud0).gender=*s2[1];
                stud0->year_of_birth=atoi(s2[2]);
                stud0->spec=s2[3];
                stud0->year=atoi(s2[4]);
                stud0->group=s2[5];
                stud0->average=atof(s2[6]);

                print_header();
                struct_out(stud0);

                printf("Address of structure: %p",(void*)stud0);
                free(stud0->name);
                free(stud0->group);
                free(stud0->spec);
                free(stud0);
                stud0=NULL;
            }
            else puts("Structure not allocated!");
            clear_string_array(s2,7);
         }
        else puts("Error at data reading!");
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

