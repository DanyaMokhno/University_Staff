#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME_SIZE 50
#define STRING_SIZE 200
#define MAX_ROW_NUMBER 2000

#ifdef WIN32
#define CLS system("cls")
#else
#define CLS system("clear")
#endif

// Function to display the main menu
void menu();

// Function to display help information
void help();

// Function to execute the program with input from a file
void run_With_File_Input();

// A function that calls functions to process the entered text, make the necessary changes and display the results
void text_processing(FILE *file);

// Function to get text from a file
void get_text(char (*text)[STRING_SIZE], int rows_lens[], FILE *file, int *row_numbers);

// Reset standard input function on UNIX-like systems
#ifndef WIN32
#define RESET_STDIN()                             \
    if ((stdin = fopen("/dev/tty", "r")) == NULL) \
        perror("Input error");
#endif

// Function to replace comments in the text
void comment_replace(char (*text)[STRING_SIZE], int rows, int rows_lens[]);

// Function to close a comment block
void close_comment(char (*text)[STRING_SIZE], int row, int last_row_index);

// Function to print text to the console
void write_text(char (*text)[STRING_SIZE], FILE *file, int row_numbers);

// Function to save the modified text to a file
void save_file(char (*text)[STRING_SIZE], int row_numbers);

// Function to execute the program with console input
void run_With_Console_Input();

int main() {
    CLS;
    menu();

    return 0;
}

void menu() {
    int value; // Value of menu parameter entered by user
    do {
        puts("There are some options:");
        puts("1 - for HELP");
        puts("2 - for RUN program with source from file");
        puts("3 - for RUN program with type in console");
        puts("0 - for EXIT program");
        printf("\nEnter option: ");
        scanf("%d", &value);
        switch (value) {
            case 1: {
                CLS;
                help();
                getchar();
            }
                break;
            case 2: {
                CLS;
                run_With_File_Input();
                getchar();
            }
                break;
            case 3: {
                CLS;
                run_With_Console_Input();
                getchar();
            }
                break;
            case 0: {
                getchar();
            }
                break;
            default: {
                puts("Incorrect key!");
                getchar();
            }
        }
        puts("Press ENTER to continue");
        getchar();
        CLS;
    } while (value != 0);
}

void help() {
    printf("\n\nPROGRAM DESCRIPTION\n\n"
           "This program provides functionality for processing and modifying text files.\n"
           "It allows you to replace inline comments in the text, format the output, and save the results to a file.\n\n"
           "OPTIONS:\n"
           "1 - HELP: Display this help message.\n"
           "2 - for RUN program with source from file: Execute the program with input read from a file.\n"
           "3 - for RUN program with type in console: Execute the program with input entered interactively in the console.\n"
           "0 - EXIT program: Exit the program.\n\n"
           "USAGE:\n"
           "- Choose the appropriate option from the main menu.\n"
           "- For 'RUN program with source from file', provide the filename when prompted.\n"
           "- For 'for RUN program with type in console', input text interactively until finished.\n"
           "- Results can be saved to a file upon request.\n\n"
           "NOTE:\n"
           "To end text input in console mode, press Ctrl+D (UNIX-like systems) or Ctrl+Z (Windows).\n");
}

void run_With_File_Input() {
    FILE *file;                             // Input file object
    char input_file_name[FILE_NAME_SIZE];   // Input file name
    int len;                                // Length of the input file name

    getchar();
    printf("Enter your filename: ");
    fgets(input_file_name, FILE_NAME_SIZE, stdin);

    len = strlen(input_file_name);
    input_file_name[len - 1] = '\0';

    if ((file = fopen(input_file_name, "r")) != NULL) {

        text_processing(file);

        if (fclose(file) == EOF)
            printf("Error closing file!\nTry again\n");
        else
            printf("Closing OK\n");
    } else {
        printf("\nInput opening error\nMake sure the file exists\n\n");
    }
}

void text_processing(FILE *file) {
    char text[MAX_ROW_NUMBER][STRING_SIZE]; // text
    int rows_lens[MAX_ROW_NUMBER];          // Lengths of each of the lines
    int row_numbers;                        // number of lines in the text

    get_text(text, rows_lens, file, &row_numbers);

#ifndef WIN32
    if (file == stdin) RESET_STDIN()
#endif

    comment_replace(text, row_numbers, rows_lens);

    write_text(text, stdout, row_numbers);

    save_file(text, row_numbers);
}

void get_text(char (*text)[STRING_SIZE], int rows_lens[], FILE *file, int *row_numbers) {
    char string[STRING_SIZE]; // current line of text from the file in the loop
    int i;                    // iterator
    int stlen;                // current length of a line of text in a loop
    int stdin_flag;           // Flag to exclude the first line when reading from stdin
    *row_numbers = 0;
    stdin_flag = 1;
    i = 0;

    while (fgets(string, STRING_SIZE, file) != NULL) {
        stlen = strlen(string);
        if (stdin_flag && file == stdin) {
            stdin_flag = 0;
        }
        else {
            strncpy(text[i], string, stlen);
            rows_lens[*row_numbers] = stlen;
            (*row_numbers)++;
            i++;
        }
    }
}

void comment_replace(char (*text)[STRING_SIZE], int rows, int rows_lens[]) {
    int row;            // Iterator for rows in the text
    int col;            // Iterator for columns in each row
    int haveComment;    // Flag to indicate whether a line has a comment
    int isStillComment; // Flag to indicate whether a multiline comment block is in progress
    isStillComment = 0;
    for (row = 0; row < rows; row++) {
        if (text[row][0] == '/' && text[row][1] == '/' && text[row + 1][0] == '/' && text[row + 1][1] == '/' &&
            !isStillComment) {
            text[row][1] = '*';
            isStillComment = 1;
        } else if (isStillComment) {
            text[row][0] = ' ';
            text[row][1] = '*';

            if (text[row + 1][0] != '/' && text[row + 1][1] != '/') {
                if (text[row][2] != '\n') {
                    close_comment(text, row, rows_lens[row]);
                } else {
                    text[row][2] = '/';
                    text[row][3] = '\n';
                }
                isStillComment = 0;
            }
        } else {
            haveComment = 0;
            for (col = 0; col < rows_lens[row]; col++) {
                if ((text[row][col] == '/') && (text[row][col + 1] == '/')) {
                    text[row][col + 1] = '*';
                    col++;
                    haveComment = 1;
                }
            }
            if (haveComment) {
                close_comment(text, row, rows_lens[row]);
            }
        }
    }
}

void close_comment(char (*text)[STRING_SIZE], int row, int last_row_index) {
    text[row][last_row_index - 1] = ' ';
    text[row][last_row_index] = '*';
    text[row][last_row_index + 1] = '/';
    text[row][last_row_index + 2] = '\n';
}

void write_text(char (*text)[STRING_SIZE], FILE *file, int row_numbers) {
    int row; // Iterator for rows in the text
    for (row = 0; row < row_numbers; row++)
        fputs(text[row], file);
}

void save_file(char (*text)[STRING_SIZE], int row_numbers) {
    FILE *outfile;                         // Output file object
    char output_file_name[FILE_NAME_SIZE]; // Output file name
    char out_flag;                         // User input flag for saving to a file
    int len;                               // Length of the output file name

    printf("\n\nDo you want save result in file?\nYes/No (y/n): ");
    scanf("%c", &out_flag);
    if (out_flag == 'y' || out_flag == 'Y') {
        getchar();
        printf("Enter your filename: ");
        fgets(output_file_name, FILE_NAME_SIZE, stdin);
        len = strlen(output_file_name);
        output_file_name[len - 1] = '\0';
        outfile = fopen(output_file_name, "w");
        if (outfile != NULL) {
            write_text(text, outfile, row_numbers);

            if (fclose(outfile) == EOF)
                perror("\nOutput closing error");
            else
                printf("\nSuccessfully preserved\n");
        } else
            perror("Output opening error");
    }
}

void run_With_Console_Input() {
    printf("Input your text\nTo end text input, press Ctrl+D (UNIX-like systems) or Ctrl+Z (Windows).\n");
    text_processing(stdin);
}