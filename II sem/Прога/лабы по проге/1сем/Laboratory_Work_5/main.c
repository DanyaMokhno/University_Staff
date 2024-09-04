#include <stdio.h>

#define SIZE 100

void get_divs(int n, char divs[]); // ф-я получения символов разделителей

int check_s(char symb, int n, char divs[]); // ф-я проверяет, является ли символ разделителем

int find_max(int n, char divs[], char str[], int *start_max_word_index,
              int *max_len); // Функция находит индекс первого символа максимального слово и его длину

void output(int stw, int len, char str[], int word_numb);

int main() {
    char string[SIZE];        // строка
    int n;                    // кол-во символов разделителей
    char divisions[SIZE];     // массив символов разделителей
    int start_word_index = 0; // индекс с которого начинается слово
    int length = 0;           // длина максимального слова
    int word_number;          // порядковый номер слова

    fgets(string, SIZE, stdin); // получаем строку
    scanf("%i\n", &n);          // получаем кол-во символов разделителей
    get_divs(n, divisions);     // получаем разделители

    word_number = find_max(n, divisions, string, &start_word_index,
             &length); // находим длинну самого длинного слова и индекс с которого он начинается, и его порядковый номер

    output(start_word_index, length, string, word_number); // вывод

    return 0;
}

void get_divs(int n, char divs[]) {
    for (int i = 0; i < n; i++)
        scanf("%c", &divs[i]);
}

int check_s(char symb, int n, char divs[]) {
    for (int j = 0; j < n; j++)
        if (symb == divs[j])
            return 0;
    return 1;
}

int find_max(int n, char divs[], char str[], int *start_max_word_index, int *max_len) {
    int cur_len = 0, i;
    int start_word_index = 0;
    int word_number = 1, final_word_nubmer;
    for (i = 0; str[i] != '\n'; i++) {
        if (check_s(str[i], n, divs)) {
            cur_len++;
            if (*max_len <= cur_len) {
                *max_len = cur_len;
                *start_max_word_index = start_word_index;
                final_word_nubmer = word_number;
            }
        } else {
            cur_len = 0;
            start_word_index = i + 1;
            word_number++;
        }
    }
    return final_word_nubmer;
}

void output(int stw, int len, char str[], int word_numb) {
    for (int i = stw; i < stw + len; i++) // выводим слово
    {
        printf("%c", str[i]);
    }
    printf("\n%i\n", word_numb); // выводим порядковый номер слова
}

/*
hello_world*how+are*you
3
_*+

Neque.porro,quisquam:esto quit
4
:. ,

Neque.porro,quisquam:esto quit
3
:.,

iii,oooo.ppppp
2
,.
*/