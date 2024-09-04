#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME_LEN 64
#define MAX_GROUP_LEN 10
#define N 4
#define OS_TYPE linux
#ifdef OS_TYPE
    #define CLS system("clear")
#else
    #define CLS system("cls")
#endif /* OS_TYPE */

/* define structure */
struct student{
        char name[MAX_NAME_LEN];
        char gender; /* 'm' or 'f' */
        int year_of_birth;
        char spec[MAX_GROUP_LEN];
        int year;
        char group[MAX_GROUP_LEN];
        float average;
};
/* define structured type */
typedef struct student studs;

int main()
{
    studs st1[N];
    int slen, i;
    char s1[MAX_NAME_LEN];

/*Reading data from console and filling structures */
    for(i=0;i<N;i++)
    {
        CLS;
        printf("Element: %d, estimated: %d\n\n", i+1, N-i-1);
        printf("Enter lastname firstname: ");
        fgets(s1,MAX_NAME_LEN,stdin);
        slen=strlen(s1);
        s1[slen-1]='\0';
        strcpy(st1[i].name,s1);

        printf("Enter gender status (m or f): ");
        st1[i].gender=getchar();

        printf("Enter year of birth (YYYY): ");
        scanf("%d",&st1[i].year_of_birth);
        getchar();

        printf("Enter speciality code: ");
        fgets(s1,MAX_GROUP_LEN,stdin);
        slen=strlen(s1);
        s1[slen-1]='\0';
        strcpy(st1[i].spec,s1);

        printf("Enter year of education (1-5): ");
        scanf("%d",&st1[i].year);
        getchar();

        printf("Enter group code: ");
        fgets(s1,MAX_GROUP_LEN,stdin);
        slen=strlen(s1);
        s1[slen-1]='\0';
        strcpy(st1[i].group,s1);

        printf("Enter average rating (0.00-5.00): ");
        scanf("%f",&st1[i].average);
        getchar();
    }
    puts("Array is ready!");

    printf("|%20s |%6s|%6s |%10s |%6s |%6s |%5s|\n","fullname","gender","year","code","course","group","ball");
    printf("+---------------------+------+-------+-----------+-------+-------+-----+\n");

    for(i=0;i<N;i++) printf("|%20s |   %c  |%6d |%10s |%6d |%6s |%5.3f|\n",
               st1[i].name,st1[i].gender,st1[i].year_of_birth,st1[i].spec,st1[i].year,st1[i].group,st1[i].average);
    return 0;
}
