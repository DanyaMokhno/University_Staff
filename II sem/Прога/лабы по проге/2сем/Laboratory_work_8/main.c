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
    char *model;             /* Модель */
    char *brand;             /* Марка */
    int ram;                 /* Объем оперативной памяти, ГБ */
    int memory;              /* Объем постоянной памяти, ГБ */
    float screen_size;       /* Размер экрана, дюймы */
    float weight;            /* Вес, граммы */
    float price;             /* Цена, доллары */
    int *camera_resolution;  /* Разрешение камеры (по камерам) */
    int number_of_cameras;   /* кол-во камер */
} Smartphone;

typedef struct Position
{
    Smartphone *smartphone;
    int index;
    struct Position *next;
} Position;

typedef struct Storage
{
    int size;
    Position *first_pos;
} Storage;

Storage *create_storage();

void fill_storage(Storage *storage, char *filename);

Position *create_position(char *string, int index);

void set_values(Smartphone *smartphone, char *str);

void split_camera_resolution(Smartphone *smartphone, char *str);

void add(Storage *storage, Position *new_position);

//вывод
void print_table(Position *position);

void print_header();

void print(Smartphone *smartphone, int index);

void choose_to_delete(Storage *storage);

void delete_selected(Storage *storage, int index);

//удаление
void delete_storage(Storage *storage);

void delete_position(Position *position);

int main()
{
    Storage *Market;
    int len;
    char filename[MAX_FILENAME_LEN];

    /* ------------get filename--------------- */
    printf("Input filename: ");
    fgets(filename, MAX_FILENAME_LEN, stdin);
    len = (int) strlen(filename);
    filename[len - 1] = '\0';
    /* -------------------------------------- */

    Market = create_storage();

    fill_storage(Market, filename);
    if (Market->size > 0)
        choose_to_delete(Market);


    delete_storage(Market);
    return 0;
}

Storage *create_storage()
{
    Storage *storage = NULL;
    storage = malloc(sizeof(Storage));
    if (storage)
    {
        storage->size = 0;
        storage->first_pos = NULL;
    }
    return storage;
}

void fill_storage(Storage *storage, char *filename)
{
    FILE *source;
    Position *new_pos;
    char tmp_str[MAX_STR_IN_FILE_LEN];
    int i;
    source = fopen(filename, "r");
    if (source != NULL)
    {
        if (storage != NULL)
        {
            // проходимся по файлу
            for (i = 1; fgets(tmp_str, MAX_STR_IN_FILE_LEN, source); i++)
            {
                new_pos = create_position(tmp_str, i);
                add(storage, new_pos);
            }
            fclose(source);
        }
    } else
        printf("Check the existence of the file\n");
}

Position *create_position(char *string, int index)
{
    Position *position = NULL;
    position = (Position *) malloc(sizeof(Position));
    if (position)
    {
        position->index = index;
        position->next = NULL;
        position->smartphone = (Smartphone *) malloc(sizeof(Smartphone));
        if (position->smartphone != NULL)
            set_values(position->smartphone, string);
    }
    return position;
}

void set_values(Smartphone *smartphone, char *str)
{
    char *cameras;
    cameras = malloc(MAX_MODEL_NAME_LEN * sizeof(char));
    if (cameras != NULL && smartphone != NULL)
    {
        smartphone->model = malloc(sizeof(char) * MAX_MODEL_NAME_LEN);
        smartphone->brand = malloc(sizeof(char) * MAX_MODEL_NAME_LEN);
        sscanf(str, "%[^;];%[^;];%d;%d;%f;%f;%f;%[^;]", smartphone->model, smartphone->brand,
               &(smartphone->ram), &(smartphone->memory), &(smartphone->screen_size),
               &(smartphone->weight), &(smartphone->price), cameras);
        split_camera_resolution(smartphone, cameras);
    }
    free(cameras);
}

void split_camera_resolution(Smartphone *smartphone, char *str)
{
    int i, j, k;
    char *tmp_str;
    int len;
    int number;
    if (smartphone)
    {
        len = (int) strlen(str);
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
}

void add(Storage *storage, Position *new_position)
{
    // вставка в начало
    if (storage && new_position)
    {
        storage->size++;
        new_position->next = storage->first_pos;
        storage->first_pos = new_position;
    }
}

void choose_to_delete(Storage *storage)
{
    int val;
    do
    {
        if (storage->size > 0)
        {
            print_header();
            print_table(storage->first_pos);
        }
        printf("input the index of element you want delete or 0 to exit: ");
        scanf("%d", &val);
        if (val > 0)
            delete_selected(storage, val);

    } while (val != 0);
}

void print_header()
{
    printf("| %-5s | %-20s | %-15s | %-5s | %-5s | %-6s | %-7s | %-8s | %-17s |\n",
           "№", "Model", "Brand", "RAM", "Storage", "Screen", "Weight", "Price", "Camera Resolution");
}

void print_table(Position *position)
{
    if (position != NULL)
    {
        print_table(position->next);
        print(position->smartphone, position->index);
    }
}

void print(Smartphone *smartphone, int index)
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
    printf("| %3i | %-20s | %-15s | %-3dGB | %-5dGB | %-5.2f\" | %-6.2fg | $%-7.2f | %15smp |\n",
           index, smartphone->model, smartphone->brand, smartphone->ram, smartphone->memory,
           smartphone->screen_size, smartphone->weight, smartphone->price, cameras_res);
    free(cameras_res);
}

void delete_selected(Storage *storage, int index)
{
    Position *cur, *tmp;
    cur = storage->first_pos;

    if (storage->size == 0) printf("Market is empty\n");
    else
    {
        if (storage->size <= index)
        {
            storage->first_pos = cur->next;
            delete_position(cur);
        } else
        {
            while (cur != NULL)
            {
                if (cur->next->index == index)
                {
                    tmp = cur->next;
                    cur->next = tmp->next;
                    delete_position(tmp);
                    cur->index--;
                    cur = NULL;
                } else
                {
                    cur->index--;
                    cur = cur->next;
                }
            }
        }
        storage->size--;
    }
}

void delete_position(Position *position)
{
    free(position->smartphone->model);
    free(position->smartphone->brand);
    free(position->smartphone->camera_resolution);
    free(position->smartphone);
    position->next = NULL;
    free(position);
}

void delete_storage(Storage *storage)
{
    Position *cur, *next;
    cur = storage->first_pos;
    while (cur != NULL)
    {
        next = cur->next;
        delete_position(cur);
        cur = next;
    }
    free(storage);
}


