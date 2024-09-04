#include <stdio.h>

#define SIZE 100

void get_divs(int n, char divs[]);

int check_s(char symb, int n, char divs[]);

int find_max(int n, char divs[], char str[], int *start_max_word_index, int *max_len);

void output(int stw, int len, char str[], int word_numb);

int main()
{
    char string[SIZE];
    int n;
    char divisions[SIZE];
    int start_word_index = 0;
    int length = 0;
    int word_number;

    fgets(string, SIZE, stdin);
    scanf("%i\n", &n);
    get_divs(n, divisions);

    word_number = find_max(n, divisions, string, &start_word_index,
                           &length);

    output(start_word_index, length, string, word_number);

    return 0;
}

void get_divs(int n, char divs[])
{
    for (int i = 0; i < n; i++)
        scanf("%c", &divs[i]);
}

int check_s(char symb, int n, char divs[])
{
    for (int j = 0; j < n; j++)
        if (symb == divs[j])
            return 0;
    return 1;
}

int find_max(int n, char divs[], char str[], int *start_max_word_index, int *max_len)
{
    int cur_len = 0, i;
    int start_word_index = 0;
    int word_number = 1, final_word_nubmer;
    for (i = 0; str[i] != '\n'; i++)
    {

        if (check_s(str[i], n, divs))
        {
            cur_len++;
            if (*max_len <= cur_len)
            {
                *max_len = cur_len;
                *start_max_word_index = start_word_index;
                final_word_nubmer = word_number;
            }
        }
        else
        {
            cur_len = 0;
            start_word_index = i + 1;
            word_number++;
        }
    }
    return final_word_nubmer;
}

void output(int stw, int len, char str[], int word_numb)
{
    for (int i = stw; i < stw + len; i++)
    {
        printf("%c", str[i]);
    }
    printf("\n%i", word_numb);
}
