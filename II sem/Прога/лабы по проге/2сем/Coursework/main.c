#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef WIN32
#include <stdint.h>
#define CLS system("cls");
#else
#define CLS system("clear");
#endif
#define PRINT_LINE puts("+-----+----------------------+-----------------+-------+---------+--------+---------+----------+-------------------+");
#define MIN(a, b) (a < b) ? a : b

/* start define bool type */
typedef uint8_t bool;
enum BOOL
{
    false, true
};
/* end define bool type */

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
} Brand;

typedef struct Brands
{
    Brand *first_brand;
} Brands;

typedef struct Smartphone
{
    char *model;             /* Model */
    Brand *brand;            /* Brand */
    int ram;                 /* RAM size, GB */
    int memory;              /* Storage capacity, GB */
    float screen_size;        /* Screen size, inches */
    float weight;             /* Weight, grams */
    float price;              /* Price, dollars */
    int *camera_resolution;  /* Camera resolution (per camera) */
    int number_of_cameras;   /* Number of cameras */

    int index;               /* Index */
    struct Smartphone *next; /* Pointer to the next element in the list */
    struct Smartphone *prev; /* Pointer to the previous element in the list */
} Smartphone;

typedef struct Storage
{
    int size;
    bool saved;
    Smartphone *first_pos;
    Smartphone *last_pos;
} Storage;

typedef float(Getters)(Smartphone *smartphone);

typedef char *(StrGetters)(Smartphone *smartphone);

/*--------- Define functions -----------*/

/* Function to create an empty storage */
Storage *create_storage();

/* Function to create an empty list of brands */
Brands *create_brands();

/* Function to open a file for reading */
FILE *open_file();

/* Function to fill the storage with smartphones from a file */
void fill_storage(Storage *storage, FILE *source, Brands *brands);

/* Function to create a new smartphone with a given index */
Smartphone *create_position(int index);

/* Function to set values for a smartphone */
void set_values(Smartphone *smartphone, char *str, Brands *brands);

/* Function to set the brand for a smartphone */
void set_brand(Smartphone *smartphone, char *brand, Brands *brands);

/* Function to split camera resolutions from a string and set them to a smartphone */
void split_camera_resolution(Smartphone *smartphone, char *str);

/* Function to add a smartphone after a specified position in the storage */
void add(Storage *storage, Smartphone *cur_position, Smartphone *new_position);

/* Function to add a smartphone as the first element in the storage */
void add_first(Storage *storage, Smartphone *new_position);

/* Main menu function */
void menu(Storage *storage, Brands *brands, FILE *file);

/* Function to display help information */
void help();

/* Function to print the storage table */
void print_table(Storage *storage);

/* Function to print the header of the storage table */
void print_header();

/* Function to print a smartphone's information in the table format */
void print(Smartphone *smartphone);

/* Function to concatenate camera resolutions into a string */
char *glue_camera_resolutions(Smartphone *smartphone);

/* Function to read a string from the input */
void get_string(char *string, int max_len);

/* Function to insert a smartphone at a specified index in the storage */
void insert_selected(Storage *storage, Smartphone *new, int index);

/* Function to delete a smartphone from the storage by its index */
void delete_selected(Storage *storage, int index);

/* Function to change the information of a smartphone in the storage */
void change_position(Storage *storage, int index, Brands *brands);

/* Function to print all available brands */
void print_brands(Brands *brands);

/* Function to find smartphones by brand */
int find_brands(Storage *storage, Smartphone **arr, Brands *brands, int value);

/* Function to find smartphones by numeric attribute */
int find(Storage *storage, Smartphone **arr, Getters get, float search_val);

/* Function to find smartphones by string attribute */
int find_str(Storage *storage, Smartphone **arr, StrGetters str_get, char *search_str);

/* Function to print the table of smartphones from arr */
void print_arr(Smartphone **arr, int size);

/* Function to perform sorting of smartphones */
void sorting(Smartphone **arr, int b, int e, bool is_str, Getters get, StrGetters str_get);

/* Function to swap two smartphone pointers */
void swap(Smartphone **a, Smartphone **b);

/* -------- getters -------- */

/* Getter function for the model attribute */
char *get_model(Smartphone *smartphone);

/* Getter function for the brand attribute */
char *get_brand(Smartphone *smartphone);

/* Getter function for the RAM attribute */
float get_ram(Smartphone *smartphone);

/* Getter function for the memory attribute */
float get_memory(Smartphone *smartphone);

/* Getter function for the screen size attribute */
float get_screen_size(Smartphone *smartphone);

/* Getter function for the weight attribute */
float get_weight(Smartphone *smartphone);

/* Getter function for the price attribute */
float get_price(Smartphone *smartphone);

/* Getter function for the camera resolution attribute */
float get_camera_resolution(Smartphone *smartphone);

/* ------------------------ */

/* Function to print menu options for search and sort */
void print_opt();

/* Function to save the storage to a file */
void save_storage(Storage *storage, FILE *file);

/* Function to delete a smartphone from memory */
void delete_position(Smartphone *position);

/* Function to delete the list of brands from memory */
void delete_brands(Brands *brand);

/* Function to delete the storage from memory */
void delete_storage(Storage *storage);

/*--------- End define functions -----------*/

int main()
{
    Storage *Market = NULL; /* Head of storage list */
    Brands *brands = NULL;  /* Head of brands list */
    FILE *file;             /* Source/destination file */
    file = open_file();
    Market = create_storage();
    brands = create_brands();
    if (Market && brands)
    {
        fill_storage(Market, file, brands);
        if (Market->size >= 0)
            menu(Market, brands, file);

        /*---- destroy structs ----*/
        delete_storage(Market);
        delete_brands(brands);
    }
    return 0;
}

Storage *create_storage()
{
    Storage *storage;   /* Head of storage list */
    storage = malloc(sizeof(Storage));
    if (storage)
    {
        storage->size = 0;
        storage->saved = false;
        storage->first_pos = NULL;
        storage->last_pos = NULL;
    }
    return storage;
}

Brands *create_brands()
{
    Brands *brands; /* Head of brands list */
    brands = malloc(sizeof(Brands));
    if (brands)
    {
        brands->first_brand = NULL;
    }
    return brands;
}

FILE *open_file()
{
    char filename[MAX_FILENAME_LEN];    /* Name of source/destination file */
    char create;                        /* Yes/No chosen */
    FILE *file;                         /* File object */
    printf("Input filename: ");
    get_string(filename, MAX_FILENAME_LEN);
    file = fopen(filename, "r+");
    if (!file)
    {
        printf("File not exist!\nDo you want create file?(y/n): ");
        create = (char) getchar();
        if (create == 'y' || create == 'Y') file = fopen(filename, "w");
    }
    return file;
}

void fill_storage(Storage *storage, FILE *source, Brands *brands)
{
    Smartphone *new_pos;                /* New element of list */
    char tmp_str[MAX_STR_IN_FILE_LEN];  /* String from source file */
    int i;                              /* Iterator */
    if (storage != NULL)
    {
        if (source != NULL)
        {
            for (i = 1; fgets(tmp_str, MAX_STR_IN_FILE_LEN, source); i++)
            {
                new_pos = create_position(i);
                if (new_pos)
                {
                    set_values(new_pos, tmp_str, brands);
                    add(storage, storage->last_pos, new_pos);
                }
            }
            storage->saved = true;
        } else
            storage->size = -1;
    }
}

Smartphone *create_position(int index)
{
    Smartphone *position = NULL;    /* New element of list */
    position = (Smartphone *) malloc(sizeof(Smartphone));
    if (position)
    {
        position->index = index;
        position->next = NULL;
    }
    return position;
}

void set_values(Smartphone *smartphone, char *str, Brands *brands)
{
    char *brand_name;   /* String with name of brand */
    char *cameras;      /* String with camera resolutions */
    smartphone->model = malloc(sizeof(char) * MAX_MODEL_NAME_LEN);
    cameras = malloc(MAX_MODEL_NAME_LEN * sizeof(char));
    smartphone->brand = NULL;
    brand_name = malloc(sizeof(char) * MAX_MODEL_NAME_LEN);
    if (cameras && brand_name)
    {
        if (str != NULL)
            sscanf(str, "%[^,],%[^,],%d,%d,%f,%f,%f,%[^,]", smartphone->model, brand_name,
                   &(smartphone->ram), &(smartphone->memory), &(smartphone->screen_size),
                   &(smartphone->weight), &(smartphone->price), cameras);
        else
        {
            printf("input model: ");
            get_string(smartphone->model, MAX_MODEL_NAME_LEN);
            printf("input brand: ");
            get_string(brand_name, MAX_MODEL_NAME_LEN);
            printf("input ram: ");
            scanf("%d", &(smartphone->ram));
            printf("input memory: ");
            scanf("%d", &(smartphone->memory));
            printf("input screen size: ");
            scanf("%f", &(smartphone->screen_size));
            printf("input weight: ");
            scanf("%f", &(smartphone->weight));
            printf("input price: ");
            scanf("%f", &(smartphone->price));
            getchar();
            printf("input cameras: ");
            get_string(cameras, MAX_MODEL_NAME_LEN);
        }
        set_brand(smartphone, brand_name, brands);
        split_camera_resolution(smartphone, cameras);
        free(cameras);
    }
}

void set_brand(Smartphone *smartphone, char *brand, Brands *brands)
{
    Brand *cur_brand;           /* Current element of brand list */
    Brand *prev_brand = NULL;   /* Previous element of brand list */
    cur_brand = brands->first_brand;

    while (cur_brand != NULL)
    {
        if (!strcmp(brand, cur_brand->name))
            smartphone->brand = cur_brand;
        prev_brand = cur_brand;
        cur_brand = cur_brand->next;
    }
    if (smartphone->brand == NULL)
    {
        cur_brand = malloc(sizeof(Brand));
        cur_brand->name = brand;
        cur_brand->next = NULL;
        if (prev_brand)
            prev_brand->next = cur_brand;
        else
            brands->first_brand = cur_brand;
        smartphone->brand = cur_brand;
    } else free(brand);
}

void split_camera_resolution(Smartphone *smartphone, char *str)
{
    int i, j, k;    /* Iterators */
    char *tmp_str;  /* String for contain numbers from file */
    int len;        /* Length of source string */
    int number;     /* Number of cameras in the smartphone */
    if (smartphone)
    {
        len = (int) strlen(str);
        for (i = 0, number = 1; i < len; i++) if (str[i] == '+') number++;
        tmp_str = malloc(5 * sizeof(char));
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

void add(Storage *storage, Smartphone *cur_position, Smartphone *new_position)
{
    if (storage)
    {
        storage->size++;
        if (!cur_position)
        {
            add_first(storage, new_position);
        } else if (new_position)
        {
            if (cur_position->next == NULL)
            {
                cur_position->next = new_position;
                new_position->prev = cur_position;
                storage->last_pos = new_position;
            } else
            {
                new_position->next = cur_position->next;
                cur_position->next->prev = new_position;
                cur_position->next = new_position;
                new_position->prev = cur_position;
            }
        }
    }
}

void add_first(Storage *storage, Smartphone *new_position)
{
    if (storage && new_position)
    {
        storage->first_pos = new_position;
        storage->last_pos = new_position;
    }
}

void menu(Storage *storage, Brands *brands, FILE *file)
{
    int global_menu_choice;                 /* Variable to store the user's choice for the menu option */
    int val;                                /* Variable used for various purposes, such as indexing and storing user input */
    int i;                                  /* Iterator */
    char search_string[MAX_MODEL_NAME_LEN]; /* String to store the search string input by the user */
    float search_val;                       /* Variable to store the search value input by the user */
    Smartphone *position;                   /* Pointer to a Smartphone structure, used for various operations within the menu */
    Smartphone **arr;                       /* Pointer to an array of pointers to Smartphone structures, used for storing positions for searching or sorting */
    Getters *getters[6];                    /* Array of function pointers to getter functions for different attributes of a smartphone */
    StrGetters *str_getters[2];             /* Array of function pointers to getter functions specifically for string attributes of a smartphone */

    str_getters[0] = get_model;
    str_getters[1] = get_brand;
    getters[0] = get_ram;
    getters[1] = get_memory;
    getters[2] = get_screen_size;
    getters[3] = get_weight;
    getters[4] = get_price;
    getters[5] = get_camera_resolution;
    do
    {
        CLS
        if (storage->saved) puts("\x1b[1;32mSaved\x1b[0m");
        else puts("\x1b[1;4;31mDon't saved\x1b[0m");
        puts("There are some options:");
        puts("1 - for HELP");
        puts("2 - for add position into Market");
        puts("3 - for insert position into Market");
        puts("4 - for remove position from Market");
        puts("5 - for change position into Market");
        puts("6 - for find position");
        puts("7 - for sort storage");
        puts("8 - for print storage");
        puts("9 - for save storage");
        puts("0 - for EXIT program");
        puts("\nEnter option: ");
        scanf("%d", &global_menu_choice);
        getchar();
        switch (global_menu_choice)
        {
            case 1:
            {
                CLS
                help();
            }
                break;
            case 2:
            {
                position = create_position(storage->size + 1);
                if (position)
                {
                    set_values(position, NULL, brands);
                    add(storage, storage->last_pos, position);
                    storage->saved = false;
                }
            }
                break;
            case 3:
            {
                CLS
                print_table(storage);
                puts("input index for insert: ");
                scanf("%i", &val);
                getchar();
                if (val > 0)
                {
                    position = create_position(val);
                    if (position)
                    {
                        set_values(position, NULL, brands);
                        insert_selected(storage, position, val);
                        storage->saved = false;
                    }
                } else printf("\x1b[1;31mindex is out of list\x1b[0m\n");
            }
                break;
            case 4:
            {
                CLS
                if (storage->size == 0) printf("Market is empty\n");
                else
                {
                    print_table(storage);
                    puts("input index: ");
                    scanf("%i", &val);
                    getchar();
                    if (val >= 1 && val <= storage->size)
                    {
                        delete_selected(storage, val);
                        storage->saved = false;
                    } else printf("\x1b[1;31mindex is out of list\x1b[0m\n");
                }
            }
                break;
            case 5:
            {
                CLS
                print_table(storage);
                puts("input index: ");
                scanf("%i", &val);
                getchar();
                if (val > 0)
                {
                    change_position(storage, val, brands);
                    storage->saved = false;
                }
            }
                break;
            case 6:
            {
                CLS
                print_table(storage);
                puts("select the parameter to be searched for");
                print_opt();
                puts("input option: ");
                scanf("%i", &val);
                if (val > 0 && val < 9)
                {
                    arr = malloc(storage->size * sizeof(Smartphone *));
                    if (arr)
                    {
                        if (val == 2)
                        {
                            print_brands(brands);
                            puts("input search value:");
                            scanf("%i", &val);
                            val = find_brands(storage, arr, brands, val);
                        } else if (val < 3)
                        {
                            puts("input search string:");
                            getchar();
                            get_string(search_string, MAX_MODEL_NAME_LEN);
                            val = find_str(storage, arr, str_getters[val - 1], search_string);
                        } else
                        {
                            puts("input search value:");
                            scanf("%f", &search_val);
                            val = find(storage, arr, getters[val - 3], search_val);
                        }
                        /* print table from arr */
                        print_arr(arr, val);
                    }
                    free(arr);
                } else puts("\x1b[1;31mIncorrect key!\x1b[0m");
                getchar();
            }
                break;
            case 7:
            {
                CLS
                print_table(storage);
                puts("select the parameter by which the sorting will be performed");
                print_opt();
                puts("input option: ");
                scanf("%i", &val);
                if (val > 0 && val < 9)
                {
                    arr = malloc(storage->size * sizeof(Smartphone *));
                    if (arr)
                    {
                        for (i = 0, position = storage->first_pos; i < storage->size; i++, position = position->next)
                            arr[i] = position;
                        if (val > 0 && val < 3)
                            sorting(arr, 0, storage->size - 1, true, NULL, str_getters[val - 1]);
                        else if (val > 0)
                            sorting(arr, 0, storage->size - 1, false, getters[val - 3], NULL);
                        /*print table from arr*/
                        print_arr(arr, storage->size);
                    }
                    free(arr);
                } else puts("\x1b[1;31mIncorrect key!\x1b[0m");
                getchar();
            }
                break;
            case 8:
            {
                CLS
                print_table(storage);
                printf("size: %d\n", storage->size);
            }
                break;
            case 9:
            {
                CLS
                save_storage(storage, file);
            }
                break;
            case 0:
            {
                getchar();
            }
                break;
            default:
            {
                puts("\x1b[1;31mIncorrect key!\x1b[0m");
                getchar();
            }

        }
        puts("Press ENTER to continue");
        getchar();
    } while (global_menu_choice != 0);
}

void help()
{
    printf("\n\nSMARTPHONE MARKET MANAGEMENT SYSTEM\n\n"
           "DESCRIPTION:\n"
           "This program allows you to manage a list of smartphones in a market.\n"
           "You can add, insert, remove, modify, find, sort, print, and save smartphone positions.\n\n"
           "OPTIONS:\n"
           "1 - HELP: Display this help message.\n"
           "2 - Add Position: Add a new smartphone position to the market.\n"
           "3 - Insert Position: Insert a new smartphone position at a specific index in the market.\n"
           "4 - Remove Position: Remove a smartphone position from the market.\n"
           "5 - Change Position: Modify details of a smartphone position.\n"
           "6 - Find Position: Search for smartphone positions based on various criteria.\n"
           "7 - Sort Storage: Sort the list of smartphone positions based on selected parameters.\n"
           "8 - Print Storage: Display all smartphone positions in the market.\n"
           "9 - Save Storage: Save the current list of smartphone positions to a file.\n"
           "0 - Exit Program: Exit the program.\n\n"
           "USAGE:\n"
           "- Choose the appropriate option from the main menu.\n"
           "- For 'Add Position', enter details for the new smartphone when prompted.\n"
           "- For 'Insert Position', specify the index and enter details for the new smartphone.\n"
           "- For 'Remove Position', input the index of the smartphone to be removed.\n"
           "- For 'Change Position', input the index of the smartphone to modify and enter updated details.\n"
           "- For 'Find Position', choose the search parameter and enter the search value.\n"
           "- For 'Sort Storage', select the parameter for sorting the smartphone positions.\n"
           "- For 'Print Storage', display all smartphone positions currently in the market.\n"
           "- For 'Save Storage', save the current list of smartphones to a file.\n");
}

void print_table(Storage *storage)
{
    Smartphone *cur;    /* cur element in list */
    cur = storage->first_pos;
    print_header();
    while (cur != NULL)
    {
        print(cur);
        cur = cur->next;
    }
    PRINT_LINE
}

void print_header()
{
    PRINT_LINE
    printf("|  %-4s | %-20s | %-15s | %-5s | %-5s | %-6s | %-7s | %-8s | %-17s |\n",
           "N\x1b[4mo\x1b[0m", "Model", "Brand", "RAM", "Storage", "Screen", "Weight", "Price", "Camera Resolution");
    PRINT_LINE
}

void print(Smartphone *smartphone)
{
    char *camera_res;   /* string for contain glued camera resolution */
    camera_res = glue_camera_resolutions(smartphone);
    printf("| %3i | %-20s | %-15s | %-3dGB | %-5dGB | %-5.2f\" | %-6.2fg | $%-7.2f | %15smp |\n",
           smartphone->index, smartphone->model, smartphone->brand->name, smartphone->ram, smartphone->memory,
           smartphone->screen_size, smartphone->weight, smartphone->price, camera_res);
    free(camera_res);
}

char *glue_camera_resolutions(Smartphone *smartphone)
{
    int i, j, k;        /* Iterators */
    char *cameras_res;  /* string for contain glued camera resolution */
    char tmp_cam[4];    /* string for temporary containment of number from array of camera resolutions */

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
    cameras_res[j] = '\0';
    return cameras_res;
}

void insert_selected(Storage *storage, Smartphone *new, int index)
{
    Smartphone *cur;    /* Current element of list */

    if (storage->size == 0)
    {
        add_first(storage, new);
        storage->size++;
    } else if (storage->last_pos->index < index)
    {
        cur = storage->last_pos;
        new->index = storage->size + 1;
        add(storage, cur, new);
    } else
    {
        cur = storage->last_pos;
        while (cur)
        {
            cur->index++;
            if (cur->index == index + 1)
            {
                if (index == 1)
                {
                    storage->first_pos = new;
                    new->next = cur;
                    cur->prev = new;
                } else
                    add(storage, cur->prev, new);
                cur = NULL;
            } else
                cur = cur->prev;
        }
    }
}

void delete_selected(Storage *storage, int index)
{
    Smartphone *cur;    /* Current element of list */
    Smartphone *tmp;    /* Temporary pointer to the element being deleted */
    cur = storage->first_pos;

    if (storage->size == 1)
    {
        tmp = cur;
        storage->first_pos = NULL;
        storage->last_pos = NULL;
        storage->size = 0;
        free(tmp);
        printf("Market is empty\n");
    } else if (storage->last_pos->index == index)
    {
        cur = storage->last_pos;
        storage->last_pos = cur->prev;
        storage->last_pos->next = NULL;
        delete_position(cur);
        storage->size--;
    } else
    {
        cur = storage->last_pos;
        while (cur != NULL)
        {
            cur->index--;
            if (cur->prev->index == index)
            {
                tmp = cur->prev;
                cur->prev = tmp->prev;
                if (cur->index == 1)
                {
                    storage->first_pos = cur;
                    cur->prev = NULL;
                } else
                    tmp->prev->next = cur;
                delete_position(tmp);
                cur = NULL;
                storage->size--;
            } else
                cur = cur->prev;
        }
    }
}

void change_position(Storage *storage, int index, Brands *brands)
{
    Smartphone *item;   /* Current/changeable element of list */
    char *brand_name;   /* String with name of brand */
    char *cameras;      /* String with camera resolutions */

    brand_name = malloc(sizeof(char) * MAX_MODEL_NAME_LEN);
    item = storage->first_pos;

    while (item->index != index) item = item->next;

    printf("\x1b[1;33mOld model name: %s\x1b[0m\n", item->model);
    printf("\x1b[1;36mNew model name: ");
    get_string(item->model, MAX_MODEL_NAME_LEN);

    printf("\x1b[1;33mOld brand: %s\x1b[0m\n", item->brand->name);
    printf("\x1b[1;36minput brand: ");
    get_string(brand_name, MAX_MODEL_NAME_LEN);
    set_brand(item, brand_name, brands);

    printf("\x1b[1;33mOld ram: %i\x1b[0m\n", item->ram);
    printf("\x1b[1;36minput ram: ");
    scanf("%d", &(item->ram));

    printf("\x1b[1;33mOld memory: %i\x1b[0m\n", item->memory);
    printf("\x1b[1;36minput memory: ");
    scanf("%d", &(item->memory));

    printf("\x1b[1;33mOld screen size: %.2f\x1b[0m\n", item->screen_size);
    printf("\x1b[1;36minput screen size: ");
    scanf("%f", &(item->screen_size));

    printf("\x1b[1;33mOld weight: %.2f\x1b[0m\n", item->weight);
    printf("\x1b[1;36minput weight: ");
    scanf("%f", &(item->weight));

    printf("\x1b[1;33mOld price: %.2f\x1b[0m\n", item->price);
    printf("\x1b[1;36minput price: ");
    scanf("%f", &(item->price));
    getchar();

    cameras = glue_camera_resolutions(item);
    printf("\x1b[1;33mOld camera resolutions: %s\x1b[0m\n", cameras);
    printf("\x1b[1;36minput camera resolutions: ");
    get_string(cameras, MAX_MODEL_NAME_LEN);
    split_camera_resolution(item, cameras);
    free(cameras);

}

void print_opt()
{
    puts("1 - model name\n"
         "2 - brand name\n"
         "3 - RAM size\n"
         "4 - memory size\n"
         "5 - screen size\n"
         "6 - weight\n"
         "7 - price\n"
         "8 - camera resolution");
}

void print_brands(Brands *brands)
{
    Brand *cur; /* Current brand element */
    int i;
    for (i = 0, cur = brands->first_brand; cur != NULL; i++, cur = cur->next)
        printf("%i - %s\n", i + 1, cur->name);
}

int find_brands(Storage *storage, Smartphone **arr, Brands *brands, int value)
{
    Smartphone *cur_sm; /* Current element of list */
    Brand *cur;         /* Current brand element */
    int i;              /* Iterator */

    for (i = 0, cur = brands->first_brand; i < value - 1; i++, cur = cur->next);

    cur_sm = storage->first_pos;
    for (i = 0; cur_sm != NULL;)
    {
        if (cur_sm->brand == cur)
        {
            arr[i] = cur_sm;
            i++;
        }
        cur_sm = cur_sm->next;
    }
    return i;
}

int find_str(Storage *storage, Smartphone **arr, StrGetters str_get, char *search_str)
{
    Smartphone *cur;    /* Current element of list */
    int i;              /* Integer */
    cur = storage->first_pos;
    i = 0;
    while (cur != NULL)
    {
        if ((strncmp(str_get(cur), search_str, MIN(strlen(str_get(cur)), strlen(search_str))) == 0))
        {
            arr[i] = cur;
            i++;
        }
        cur = cur->next;
    }
    return i;
}

int find(Storage *storage, Smartphone **arr, Getters get, float search_val)
{
    Smartphone *cur;    /* Current element of list */
    int i;              /* Iterator */
    cur = storage->first_pos;
    i = 0;
    while (cur != NULL)
    {
        if (search_val == get(cur))
        {
            arr[i] = cur;
            i++;
        }
        cur = cur->next;
    }
    return i;
}

void print_arr(Smartphone **arr, int size)
{
    int i;  /* Iterator */
    print_header();
    for (i = 0; i < size; i++) print(arr[i]);
    PRINT_LINE
}

void sorting(Smartphone **arr, int b, int e, bool is_str, Getters get, StrGetters str_get)
{
    int left, right;    /* Indices for the left and right boundaries of the array segment */
    float middle;       /* Middle value for numeric sorting */
    char *str_middle;   /* Middle value for string sorting */

    left = b;
    right = e;
    if (is_str)
        str_middle = str_get(arr[(left + right) / 2]);
    else
        middle = get(arr[(left + right) / 2]);
    while (left <= right)
    {
        if (is_str)
        {
            while (strcmp(str_get(arr[left]), str_middle) < 0) left++;
            while (strcmp(str_get(arr[right]), str_middle) > 0) right--;
        } else
        {
            while (get(arr[left]) < middle) left++;
            while (get(arr[right]) > middle) right--;
        }
        if (left <= right) swap(&arr[left++], &arr[right--]);
    }
    if (b < right) sorting(arr, b, right, is_str, get, str_get);
    if (e > left) sorting(arr, left, e, is_str, get, str_get);
}

void swap(Smartphone **a, Smartphone **b)
{
    Smartphone *c;  /* Temporary pointer to store the value of 'a' */
    c = *a;
    *a = *b;
    *b = c;
}

/* getters */
char *get_model(Smartphone *smartphone)
{
    return smartphone->model;
}

char *get_brand(Smartphone *smartphone)
{
    return smartphone->brand->name;
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
    return (float) smartphone->screen_size;
}

float get_weight(Smartphone *smartphone)
{
    return (float) smartphone->weight;
}

float get_price(Smartphone *smartphone)
{
    return (float) smartphone->price;
}

float get_camera_resolution(Smartphone *smartphone)
{
    int i;      /* Iterator */
    int max;    /* Max value of array */
    max = smartphone->camera_resolution[0];
    for (i = 1; i < smartphone->number_of_cameras; i++)
        if (smartphone->camera_resolution[i] > max) max = smartphone->camera_resolution[i];
    return (float) max;
}

/* ------ */

void get_string(char *string, int max_len)
{
    int len; /* Length of string */
    if (string)
    {
        fgets(string, max_len, stdin);
        len = (int) strlen(string);
        string[len - 1] = '\0';
    }
}

void save_storage(Storage *storage, FILE *file)
{
    Smartphone *cur;
    char *resolution;
    if (!file) printf("Error file saving\n");
    else
    {
        rewind(file);
        cur = storage->first_pos;
        resolution = glue_camera_resolutions(cur);
        while (cur != NULL)
        {
            fprintf(file, "%s,%s,%d,%d,%.2f,%.2f,%.2f,%s\n", cur->model, cur->brand->name,
                    cur->ram, cur->memory, cur->screen_size,
                    cur->weight, cur->price, resolution);
            cur = cur->next;
        }
        free(resolution);
        storage->saved = true;
        printf("Storage saved successfully!\n");
    }
}

void delete_position(Smartphone *position)
{
    free(position->model);
    free(position->camera_resolution);
    position->next = NULL;
    position->prev = NULL;
    free(position);
}

void delete_brands(Brands *brands)
{
    Brand *cur_brand;   /* Current element of brand list */
    Brand *tmp_brand;   /* Temporary pointer to the element being deleted */

    cur_brand = brands->first_brand;
    while (cur_brand)
    {
        free(cur_brand->name);
        tmp_brand = cur_brand;
        cur_brand = cur_brand->next;
        free(tmp_brand);
    }
    free(brands);
}

void delete_storage(Storage *storage)
{
    Smartphone *cur;    /* Current element of list */
    Smartphone *next;   /* Next element of list */
    cur = storage->first_pos;
    while (cur != NULL)
    {
        next = cur->next;
        delete_position(cur);
        cur = next;
    }
    free(storage);
}