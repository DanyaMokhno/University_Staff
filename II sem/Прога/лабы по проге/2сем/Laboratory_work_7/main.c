#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#define CLS system("cls")
#else
#define CLS system("clear")
#endif

enum
{
    MAX_STR_IN_FILE_LEN = 200,
    MAX_MODEL_NAME_LEN = 30,
    MAX_FILENAME_LEN = 20
};

typedef struct Smartphone
{
    char *model; /* Модель */
    char *brand; /* Марка */
    int ram; /* Объем оперативной памяти, ГБ */
    int memory; /* Объем постоянной памяти, ГБ */
    float screen_size; /* Размер экрана, дюймы */
    float weight; /* Вес, граммы */
    float price; /* Цена, доллары */
    int *camera_resolution; /* Разрешение камеры (по камерам) */
    int number_of_cameras;
} Smartphone;

typedef float(*Getters)(Smartphone *);

Smartphone **create_storage(int *n, char *source_file_name);

void add_new_position(Smartphone **storage, int *index, FILE *file);

void resize_storage(Smartphone ***storage, int *size);

void set_values(Smartphone *smartphone, char *str);

void split_camera_resolution(Smartphone *smartphone, char *str);

void print_table(Smartphone **storage, int n);

void print_header();

void print(Smartphone *smartphone);

void menu(Smartphone **storage, int *n, Getters *get_value);

void remove_storage(Smartphone **storage, int size);

void sort_storage(Smartphone **storage, int size, Getters get_value);

void find_element_by_str(Smartphone **storage, int size);

// функции получения полей
float get_ram(Smartphone *smartphone);

float get_memory(Smartphone *smartphone);

float get_screen_size(Smartphone *smartphone);

float get_weight(Smartphone *smartphone);

float get_price(Smartphone *smartphone);

float get_camera_resolution(Smartphone *smartphone);

int main()
{
    Smartphone **Market;
    Getters values[6];
    int number_of_products;
    int len;
    char filename[MAX_FILENAME_LEN];

    printf("Input filename: ");
    fgets(filename, MAX_MODEL_NAME_LEN, stdin);
    len = strlen(filename);
    filename[len - 1] = '\0';

    Market = create_storage(&number_of_products, filename);

    if (number_of_products)
    {
        print_table(Market, number_of_products);

        // массив с функциями
        values[0] = get_ram;
        values[1] = get_memory;
        values[2] = get_screen_size;
        values[3] = get_weight;
        values[4] = get_price;
        values[5] = get_camera_resolution;

        // запускаем цикл с менюшкой
        menu(Market, &number_of_products, values);
        // удаляем массив структур
        remove_storage(Market, number_of_products);
    } else
    {
        printf("something going wrong!!!");
    }
    return 0;
}

Smartphone **create_storage(int *n, char *source_file_name)
{
    Smartphone **storage;
    FILE *source;
    char tmp_str[MAX_STR_IN_FILE_LEN];
    int i;

    source = fopen(source_file_name, "r");
    if (source != NULL)
    {
        // считываем файл
        *n = 0;
        while ((fgets(tmp_str, MAX_STR_IN_FILE_LEN, source)) != NULL) (*n)++;
        rewind(source);
        storage = (Smartphone **) malloc(*n * sizeof(Smartphone *));
        if (storage != NULL)
        {
            // проходимся по файлу
            for (i = 0; i < *n; i++)
                add_new_position(storage, &i, source);
            fclose(source);
            return storage;
        }
    } else
        printf("Check the existence of the file\n");
    return 0;
}

void add_new_position(Smartphone **storage, int *index, FILE *file)
{
    char tmp_str[MAX_STR_IN_FILE_LEN];
    int len;
    int cnt; // counter of ;
    int i;
    fgets(tmp_str, MAX_STR_IN_FILE_LEN, file);
    len = strlen(tmp_str);
    tmp_str[len - 1] = '\0';
    for (i = 0, cnt = 0; i < len; i++) if (tmp_str[i] == ';') cnt++;
    if (cnt == 7)
    {
        if (file == stdin) resize_storage(&storage, index);
        storage[*index] = malloc(sizeof(Smartphone));
        set_values(storage[*index], tmp_str);
    } else
    {
        printf("string is not in the line with format: %s\n", tmp_str);
    }
}

void resize_storage(Smartphone ***storage, int *size)
{
    *storage = realloc(*storage, sizeof(Smartphone *) * (*size));
}

void set_values(Smartphone *smartphone, char *str)
{
    char *cameras;
    cameras = malloc(MAX_MODEL_NAME_LEN * sizeof(char));
    smartphone->model = malloc(sizeof(char) * MAX_MODEL_NAME_LEN);
    smartphone->brand = malloc(sizeof(char) * MAX_MODEL_NAME_LEN);
    sscanf(str, "%[^;];%[^;];%d;%d;%f;%f;%f;%[^;]", smartphone->model, smartphone->brand,
           &(smartphone->ram), &(smartphone->memory), &(smartphone->screen_size),
           &(smartphone->weight), &(smartphone->price), cameras);
    split_camera_resolution(smartphone, cameras);
    free(cameras);
}

void split_camera_resolution(Smartphone *smartphone, char *str)
{
    int i, j, k;
    char *tmp_str;
    int len;
    int number;
    len = strlen(str);
    for (i = 0, number = 1; i < len; i++) if (str[i] == '+') number++;
    tmp_str = malloc(4 * sizeof(char));
    smartphone->camera_resolution = malloc(sizeof(int) * number);
    if (number != 0)
    {
        for (i = 0, j = 0, k = 0; i <= len; i++, j++)
        {
            if (str[i] != '+' && str[i] != '\0')
            {
                tmp_str[j] = str[i];
            } else
            {
                smartphone->camera_resolution[k] = atoi(tmp_str);
                strcpy(tmp_str, "    ");
                k++;
                j = -1;
            }
        }
    }
    smartphone->number_of_cameras = number;
    free(tmp_str);
}

void print_table(Smartphone **storage, int n)
{
    int i;
    print_header();
    for (i = 0; i < n; i++)
        print(storage[i]);
}

void print_header()
{
    printf("| %-20s | %-15s | %-5s | %-5s | %-6s | %-7s | %-8s | %-17s |\n",
           "Model", "Brand", "RAM", "Storage", "Screen", "Weight", "Price", "Camera Resolution");
}

void print(Smartphone *smartphone)
{
    int i, j, k;
    char *cameras_res;
    char tmp_cam[4];

    cameras_res = malloc(smartphone->number_of_cameras * 3 * sizeof(char));
    for (i = 0, j = 0; i < smartphone->number_of_cameras; i++)
    {
        snprintf(tmp_cam, sizeof(tmp_cam), "%d", smartphone->camera_resolution[i]);
        for (k = 0; k < strlen(tmp_cam); k++, j++)
            cameras_res[j] = tmp_cam[k];
        if (i < smartphone->number_of_cameras - 1)
        {
            cameras_res[j] = '+';
            j++;
        }
    }
    printf("| %-20s | %-15s | %-3dGB | %-5dGB | %-5.2f\" | %-6.2fg | $%-7.2f | %15smp |\n",
           smartphone->model, smartphone->brand, smartphone->ram, smartphone->memory,
           smartphone->screen_size, smartphone->weight, smartphone->price, cameras_res);
    free(cameras_res);
}

void menu(Smartphone **storage, int *n, Getters *get_value)
{
    int value; // Value of menu parameter entered by user
    do
    {
        puts("\nThere are some options:");
        puts("1 - sort by RAM");
        puts("2 - sort by Storage");
        puts("3 - sort by screen size");
        puts("4 - sort by weight");
        puts("5 - sort by price");
        puts("6 - sort by camera resolution");
        puts("7 - add smartphone");
        puts("8 - find element by model or brand");
        puts("0 - for EXIT program");
        printf("\nEnter option: ");
        scanf("%d", &value);
        switch (value)
        {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            {
                CLS;
                sort_storage(storage, *n, get_value[value - 1]);
                print_table(storage, *n);
                getchar();
            }
                break;
            case 7:
            {
                CLS;
                fflush(stdin);
                printf("input string with new position: ");
                add_new_position(storage, n, stdin);
                *n += 1;
            }
                break;
            case 8:
            {
                getchar();
                find_element_by_str(storage, *n);
            }
                break;
            case 0:
            {
                getchar();
            }
                break;
            default:
            {
                puts("Incorrect key!");
                getchar();
            }
        }
        puts("Press ENTER to continue");
        getchar();
        CLS;
    } while (value != 0);
}

void sort_storage(Smartphone **storage, int size, Getters get_value)
{
    int gap, i, k;
    Smartphone *tmp;
    for (gap = size / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < size; i++)
        {
            for (k = i; k >= gap && get_value(storage[k - gap]) > get_value(storage[k]); k -= gap)
            {
                // Обмен элементов
                tmp = storage[k];
                storage[k] = storage[k - gap];
                storage[k - gap] = tmp;
            }
        }
    }
}

float get_ram(Smartphone *smartphone)
{
    return (float) smartphone->ram;
}

float get_memory(Smartphone *smartphone)
{
    return (float) smartphone->memory;
}

float get_screen_size(Smartphone *smartphone)
{
    return smartphone->screen_size;
}

float get_weight(Smartphone *smartphone)
{
    return smartphone->weight;
}

float get_price(Smartphone *smartphone)
{
    return smartphone->price;
}

float get_camera_resolution(Smartphone *smartphone)
{
    int i;
    int max;
    max = smartphone->camera_resolution[0];
    for (i = 1; i < smartphone->number_of_cameras; i++)
        if (smartphone->camera_resolution[i] > max) max = smartphone->camera_resolution[i];
    return (float) max;
}

void find_element_by_str(Smartphone **storage, int size)
{
    char *string;
    int i, len, found;
    printf("input: ");
    string = malloc(sizeof(char) * MAX_MODEL_NAME_LEN);
    fgets(string, MAX_MODEL_NAME_LEN, stdin);
    len = strlen(string);
    string[len - 1] = '\0';
    found = 0;
    print_header();
    for (i = 0; i < size; i++)
    {
        if (!strncmp(string, storage[i]->model, len - 1))
        {
            print(storage[i]);
            found = 1;
        }
    }
    if (!found)
    {
        CLS;
        printf("sorry, but, smartphone not found\n");
    }
    free(string);
}

void remove_storage(Smartphone **storage, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        free(storage[i]->model);
        free(storage[i]->brand);
        free(storage[i]->camera_resolution);
        free(storage[i]);
    }
    free(storage);
}