#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 7
#define MAX_LEN_NAME 100
#define TELEPHONE_LENGTH 13

typedef struct NAME
{
    char surname[MAX_LEN_NAME];
    char first_letter_name;
    char first_letter_middle_name;
} NAME;

typedef struct TELE
{
    char number[TELEPHONE_LENGTH];
} TELE;

typedef struct DATE
{
    int day;
    int month;
    int year;
} DATE;

typedef struct NOTE2
{
    NAME Name;
    TELE Tele;
    DATE Date;
} NOTE2;

void fill_note(NOTE2 *note);

void fill_name(NAME *name);

void get_string(char *str, int mx_len);

void fill_tele(TELE *tele);

void fill_date(DATE *date);

void check_correct_date(int day, int month, int year, int *flag);

void sort_note(NOTE2 *note);

void swap(NOTE2 *note, int j);

void print_header();

void show_info(NOTE2 item);

void search(NOTE2 *arr);

int main()
{
    NOTE2 BLOCK2[BLOCK_SIZE];
    int i;

    for (i = 0; i < BLOCK_SIZE; i++)
    {
        printf("Person №%i\n", i + 1);
        fill_note(&(BLOCK2[i]));
    }

    sort_note(BLOCK2);

    printf("notes sorted by the first 3 digits of the phone number:\n");
    print_header();
    for (i = 0; i < BLOCK_SIZE; i++)
    {
        show_info(BLOCK2[i]);
    }

    search(BLOCK2);

    return 0;
}

void fill_note(NOTE2 *note)
{
    fill_name(&(note->Name));
    fill_tele(&(note->Tele));
    fill_date(&(note->Date));
}

void fill_name(NAME *name)
{
    printf("Input surname: ");
    get_string(name->surname, MAX_LEN_NAME);

    printf("Input first letter of name: ");
    scanf("%c", &(name->first_letter_name));
    getchar();

    printf("Input first letter of middle name: ");
    scanf("%c", &(name->first_letter_middle_name));
    getchar();
}

void get_string(char *str, int mx_len)
{
    int len;
    fgets(str, mx_len, stdin);
    len = strlen(str);
    str[len - 1] = '\0';
}

void fill_tele(TELE *tele)
{
    char *number;
    int i;
    int flag;

    number = malloc(TELEPHONE_LENGTH * sizeof(char));
    flag = 0;
    while (!flag)
    {
        flag = 1;
        printf("Input your telephone number: ");
        get_string(number, TELEPHONE_LENGTH);

        if (number[0] == '+' || (number[0] >= 48 && number[0] <= 57))
        {
            for (i = 1; number[i] != '\0'; i++)
            {
                if (number[i] < 48 || number[i] > 57)
                    flag = 0;
            }
        }
        else
            flag = 0;

        if (flag)
            strcpy(tele->number, number);
        else
            printf("Number incorrect!!!\n");
    }
    free(number);
}

void fill_date(DATE *date)
{
    int day, month, year;
    int flag;

    flag = 0;
    while (!flag)
    {
        printf("Enter the date (day.month.year): ");
        scanf("%d.%d.%d", &day, &month, &year);
        check_correct_date(day, month, year, &flag);
        if (flag)
        {
            date->day = day;
            date->month = month;
            date->year = year;
        } else
        {
            printf("Incorrect date!!!\n");
        }
        getchar();
    }
}

void check_correct_date(int day, int month, int year, int *flag)
{
    if (month > 0 && month <= 12 && day > 0)
    {
        if ((month == 2 && ((year % 4 == 0 && day <= 29) || (year % 4 != 0 && day <= 28))) ||
            (month < 8 && month != 2 && ((month % 2 == 0 && day <= 30) || (month % 2 != 0 && day <= 31))) ||
            (month >= 8 && ((month % 2 == 0 && day <= 31) || (month % 2 != 0 && day <= 30))))
        {
            *flag = 1;
        }
    }
}

void sort_note(NOTE2 *note)
{
    int i, j;

    for (i = 0; i < BLOCK_SIZE - 1; i++)
    {
        for (j = 0; j < BLOCK_SIZE - i - 1; j++)
        {
            if (note[j].Tele.number[0] > note[j + 1].Tele.number[0] ||
                (note[j].Tele.number[0] == note[j + 1].Tele.number[0] &&
                 (note[j].Tele.number[1] > note[j + 1].Tele.number[1] ||
                  (note[j].Tele.number[1] == note[j + 1].Tele.number[1] &&
                   note[j].Tele.number[2] > note[j + 1].Tele.number[2]))))
            {
                swap(note, j);
            }
        }
    }
}

void swap(NOTE2 *note, int j)
{
    NOTE2 tmp;
    tmp = note[j];
    note[j] = note[j + 1];
    note[j + 1] = tmp;
}

void print_header(){
    int i;
    for (i = 0; i < 55; i++) putchar('-');
    putchar('\n');
    printf("| %-10s %s. %s. | %-15s | %s.%s.%s |\n", "Surname", "N", "M", "Phone Number", "Day", "Month", "Year");
    for (i = 0; i < 55; i++) putchar('-');
    putchar('\n');
}

void show_info(NOTE2 item)
{
    int i;
    printf("| %-10s %c. %c. | %-15s |   %02d.%02d.%04d   |\n",
           item.Name.surname, item.Name.first_letter_name,
           item.Name.first_letter_middle_name, item.Tele.number,
           item.Date.day, item.Date.month, item.Date.year);
}

void search(NOTE2 *arr)
{
    int i, k;
    int found;
    int stop;
    char *cur_surname;
    NOTE2 items[BLOCK_SIZE];

    cur_surname = malloc(MAX_LEN_NAME * sizeof(char));

    do
    {
        printf("\nEnter the last name of the person you want to see information about or enter \"stop\" to complete the input:\n");
        get_string(cur_surname, MAX_LEN_NAME);
        stop = strcmp("stop", cur_surname);

        if (stop != 0)
        {
            found = 0;
            for (i = 0, k = 0; i < BLOCK_SIZE; i++)
            {
                if (strcmp(cur_surname, arr[i].Name.surname) == 0)
                {
                    items[k] = arr[i];
                    k++;
                    found = 1;
                }
            }

            if (found)
            {
                print_header();
                for (i = 0; i < k; i++) {
                    show_info(items[i]);
                }
            }
            else
            {
                printf("Person not found\n");
            }
        }
    } while (stop != 0);

    free(cur_surname);
}