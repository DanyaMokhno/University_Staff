#include <stdio.h>
#include <string.h>

struct person {
    char name[64];
    char gender; //'m' or 'f'
    int year_of_birth;
};

struct student : person {
    char spec[16];
    int year;
    char group[8];
    float average;
};

void f(person &p1, char *str)
{
    strcpy(p1.name,str);
}

int main()
{
    student s1;
    person *p;
    char name[64];
    int len0;

    printf("Enter name: ");
    fgets(name,64,stdin);
    len0=strlen(name);
    name[len0-1]='\0';

    f(s1,name);
    printf("Result1: %s\n", s1.name);

    p=&s1;
    person &p_ref=s1;

    f(*p,name);
    printf("Result2: %s\n", s1.name);

    f(p_ref,name);
    printf("Result3: %s\n", s1.name);

    return 0;
}
