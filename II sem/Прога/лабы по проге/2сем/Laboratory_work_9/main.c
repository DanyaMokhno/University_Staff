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

typedef struct Brand
{
    char *name;
    struct Brand *next;
} Brands;

typedef struct Smartphone
{
    char *model;             /* Модель */
    Brands *brand;           /* Марка */
    int ram;                 /* Объем оперативной памяти, ГБ */
    int memory;              /* Объем постоянной памяти, ГБ */
    float screen_size;       /* Размер экрана, дюймы */
    float weight;            /* Вес, граммы */
    float price;             /* Цена, доллары */

    int index;               /* индекс */
    struct Smartphone *next; /* указатель на следующий элемент списка */
    struct Smartphone *prev; /* указатель на предыдущий элемент списка */
} Smartphone;

typedef struct Storage
{
    int size;
    int max_index;
    Smartphone *first_pos;
    Smartphone *last_pos;
} Storage;

Storage *create_storage();

void fill_storage(Storage *storage, char *filename, Brands **brands);

Smartphone *create_position(char *string, int index, Brands **brands);

void set_values(Smartphone *smartphone, char *str, Brands **brands);

void set_brand(Smartphone *smartphone, char *brand, Brands **brands);

void add_first(Storage *storage, Smartphone *new_position);

void add(Storage *storage, Smartphone *cur_position, Smartphone *new_position);

void choose_to_ins_or_del(Storage *storage, Brands **brands);

void print_header();

void print_table(Storage *storage);

void print(Smartphone *smartphone);

void insert_selected(Storage *storage, char *string, int index, Brands **brands);

void insert(Storage *storage, Smartphone *cur_position, Smartphone *new_position);

void delete_selected(Storage *storage, int index);

void delete_position(Smartphone *position);

void delete_brands(Brands *brand);

void delete_storage(Storage *storage);

int main()
{
    Storage *Market;
    Brands *brands = NULL;
    int len;
    char filename[MAX_FILENAME_LEN];


    /* ------------get filename--------------- */
    printf("Input filename: ");
    fgets(filename, MAX_FILENAME_LEN, stdin);
    len = (int) strlen(filename);
    filename[len - 1] = '\0';
    /* -------------------------------------- */

    Market = create_storage();

    fill_storage(Market, filename, &brands);

    if (Market->size > 0)
    {
        choose_to_ins_or_del(Market, &brands);
    }

    printf("max index: %i\nsize: %i", Market->max_index, Market->size);

    delete_brands(brands);

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
        storage->max_index = 0;
        storage->first_pos = NULL;
        storage->last_pos = NULL;
    }
    return storage;
}

void fill_storage(Storage *storage, char *filename, Brands **brands)
{
    FILE *source;
    Smartphone *new_pos;
    char tmp_str[MAX_STR_IN_FILE_LEN];
    int i;
    source = fopen(filename, "r");
    if (storage != NULL)
    {
        if (source != NULL)
        {
            // проходимся по файлу
            for (i = 1; fgets(tmp_str, MAX_STR_IN_FILE_LEN, source); i++)
            {
                new_pos = create_position(tmp_str, i, brands);
                if (i == 1) add_first(storage, new_pos);
                else add(storage, storage->last_pos, new_pos);
            }
            storage->max_index = storage->size;
            fclose(source);
        } else
        {
            storage->size = -1;
            printf("Check the existence of the file\n");
        }
    }
}

Smartphone *create_position(char *string, int index, Brands **brands)
{
    Smartphone *position = NULL;
    position = (Smartphone *) malloc(sizeof(Smartphone));
    if (position)
    {
        position->index = index;
        position->next = NULL;
        position->prev = NULL;
        set_values(position, string, brands);
    }
    return position;
}

void set_values(Smartphone *smartphone, char *str, Brands **brands)
{
    char *brand_name;
    smartphone->model = malloc(sizeof(char) * MAX_MODEL_NAME_LEN);
    smartphone->brand = NULL;
    brand_name = malloc(sizeof(char) * MAX_MODEL_NAME_LEN);
    sscanf(str, "%[^,],%[^,],%d,%d,%f,%f,%f", smartphone->model, brand_name,
           &(smartphone->ram), &(smartphone->memory), &(smartphone->screen_size),
           &(smartphone->weight), &(smartphone->price));
    set_brand(smartphone, brand_name, brands);
}

void set_brand(Smartphone *smartphone, char *brand, Brands **brands)
{
    Brands *cur_brand, *prev_brand;
    cur_brand = *brands;
    prev_brand = NULL;

    while (cur_brand != NULL)
    {
        if (strcmp(brand, cur_brand->name) == 0)
        {
            smartphone->brand = cur_brand;
        }
        prev_brand = cur_brand;
        cur_brand = cur_brand->next;
    }
    if (smartphone->brand == NULL)
    {
        cur_brand = malloc(sizeof(Brands));
        cur_brand->name = brand;
        if (prev_brand)
            prev_brand->next = cur_brand;
        else
            *brands = cur_brand;
        smartphone->brand = cur_brand;
    } else free(brand);
}

void add_first(Storage *storage, Smartphone *new_position)
{
    if (storage && new_position)
    {
        storage->first_pos = new_position;
        storage->last_pos = new_position;
        storage->size++;
    }
}

void add(Storage *storage, Smartphone *cur_position, Smartphone *new_position)
{
    //вставка в конец
    if (storage && new_position && cur_position)
    {
        storage->size++;
        if (cur_position->next == NULL)
        {
            cur_position->next = new_position;
            new_position->prev = cur_position;
            storage->last_pos = new_position;
            storage->max_index = new_position->index;

        } else
        {
            new_position->next = cur_position->next;
            cur_position->next = new_position;
            new_position->prev = cur_position;
        }
    }
}

void choose_to_ins_or_del(Storage *storage, Brands **brands)
{
    int val;
    char string[MAX_STR_IN_FILE_LEN];
    do
    {
        if (storage->size > 0)
        {
            print_table(storage);
        }

        printf("size: %i\n", storage->size);
        printf("input 1, if you want to insert element\ninput 2, if you want to delete element\ninput 0 to exit:\n");
        scanf("%i", &val);
        if (val == 1)
        {
            getchar();
            printf("input the index of element you want insert or 0 to exit: ");
            scanf("%d", &val);
            if (val > 0)
            {
                getchar();
                printf("input the string: ");
                fgets(string, MAX_STR_IN_FILE_LEN, stdin);
                insert_selected(storage, string, val, brands);
            }
        } else if (val == 2)
        {
            printf("input the index of element you want delete or 0 to exit: ");
            scanf("%d", &val);
            if (val > 0)
            {
                getchar();
                delete_selected(storage, val);
            }
        }
    } while (val != 0);
}

void print_header()
{
    printf("| %-5s | %-20s | %-15s | %-5s | %-5s | %-6s | %-7s | %-8s |\n",
           "№", "Model", "Brand", "RAM", "Storage", "Screen", "Weight", "Price");
    printf("+-----+----------------------+-----------------+-------+---------+--------+---------+----------+\n");
}

void print_table(Storage *storage)
{
    Smartphone *cur;
    cur = storage->first_pos;
    print_header();
    while (cur != NULL)
    {
        print(cur);
        cur = cur->next;
    }
}

void print(Smartphone *smartphone)
{
    printf("| %3i | %-20s | %-15s | %-3dGB | %-5dGB | %-5.2f\" | %-6.2fg | $%-7.2f |\n",
           smartphone->index, smartphone->model, smartphone->brand->name, smartphone->ram, smartphone->memory,
           smartphone->screen_size, smartphone->weight, smartphone->price);
}

void insert_selected(Storage *storage, char *string, int index, Brands **brands)
{
    Smartphone *new, *cur;
    int found;

    found = 0;
    new = create_position(string, index, brands);
    if (storage->max_index < index)
    {
        cur = storage->last_pos;
        add(storage, cur, new);
        storage->max_index = index;
    } else
    {
        cur = storage->first_pos;
        while (cur)
        {
            if (cur->index < index && cur->next->index > index)
            {
                add(storage, cur, new);
                cur = NULL;
            } else if (cur->index == index)
            {
                insert(storage, cur, new);
                cur->index++;
                cur = cur->next;
                found = 1;
            } else
            {
                if (!found) cur = cur->next;
                else
                {
                    cur->index++;
                    if (cur->next && cur->next->index - cur->index > 1) cur = NULL;
                    else cur = cur->next;
                }
            }
        }
        if (storage->max_index < storage->last_pos->index) storage->max_index = storage->last_pos->index;
    }
}

/* вставка перед элементом */
void insert(Storage *storage, Smartphone *cur_position, Smartphone *new_position)
{
    Smartphone *prev;
    if (storage && cur_position && new_position)
    {
        if (storage->first_pos == cur_position)
        {
            new_position->next = cur_position;
            cur_position->prev = new_position;
            storage->first_pos = new_position;
        } else
        {
            prev = cur_position->prev;
            new_position->next = cur_position;
            new_position->prev = prev;
            prev->next = new_position;
            cur_position->prev = new_position;
        }
        storage->size++;
    }
}

void delete_selected(Storage *storage, int index)
{
    Smartphone *cur, *tmp;
    Brands *brand;
    cur = storage->first_pos;
    if (storage->size == 0) printf("Market is empty\n");
    else
    {
        // находим бренд по индексу
        while (cur)
        {
            if (cur->index == index)
                brand = cur->brand;
            cur = cur->next;
        }
        // ищем что удалить
        if (storage->size == 1)
        {
            tmp = storage->first_pos;
            storage->first_pos = NULL;
            storage->last_pos = NULL;
            storage->size = 0;
            storage->max_index = 0;
            free(tmp);
            printf("Market is empty\n");
        } else if (storage->max_index <= index || storage->last_pos->brand == brand)
        {
            brand = storage->last_pos->brand;
            cur = storage->last_pos;
            storage->last_pos = cur->prev;
            storage->last_pos->next = NULL;
            delete_position(cur);
            storage->max_index = storage->last_pos->index;
            storage->size--;
        }
        cur = storage->first_pos;
        while (cur != NULL)
        {
            if (storage->first_pos != NULL && storage->first_pos->brand == brand)
            {
                storage->first_pos = cur->next;
                cur->next->prev = NULL;
                delete_position(cur);
                cur = storage->first_pos;
                storage->size--;
            } else if (cur->next && cur->next->brand == brand)
            {
                tmp = cur->next;
                cur->next = tmp->next;
                tmp->next->prev = cur;
                delete_position(tmp);
                cur = cur->next;
                storage->size--;
            } else
                cur = cur->next;
        }
    }
}

void delete_position(Smartphone *position)
{
    free(position->model);
    position->next = NULL;
    position->prev = NULL;
    free(position);
}

void delete_brands(Brands *brand)
{
    Brands *tmp_brand;
    while (brand)
    {
        free(brand->name);
        tmp_brand = brand;
        brand = brand->next;
        free(tmp_brand);
    }
}

void delete_storage(Storage *storage)
{
    Smartphone *cur, *next;
    cur = storage->first_pos;
    while (cur != NULL)
    {
        next = cur->next;
        delete_position(cur);
        cur = next;
    }
    free(storage);
}