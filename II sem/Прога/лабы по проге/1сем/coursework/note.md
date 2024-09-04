## Функция вариант 1
```c
void comment_replace(char (*text)[STRING_SIZE], int rows, int rowslens[]) {
    int row, col, flag;
    for (row = 0; row < rows + 1; row++) {
        flag = 0;
        for (col = 0; col < rowslens[row]; col++) {
            if ((text[row][col] == '/') && (text[row][col + 1] == '/')) {
                text[row][col + 1] = '*';
                col++;
                flag = 1;
            }
        }
        if (flag) {
            text[row][rowslens[row]-1] = ' ';
            text[row][rowslens[row]] = '*';
            text[row][rowslens[row]+1] = '/';
            text[row][rowslens[row]+2] = '\n';
        }
    }
}
```