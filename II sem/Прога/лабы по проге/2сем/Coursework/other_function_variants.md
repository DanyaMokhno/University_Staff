## Find вариадическая (с переменным кол-вом параметров)
```c

#include <stdarg.h>
int find(Storage *storage, Smartphone **arr, bool is_str, ...)
{
    va_list vl;
    Getters *get;
    double search_val;
    StrGetters *str_get;
    char *search_str;

    Smartphone *cur;
    int i;

    va_start(vl, is_str);
    if (is_str)
    {
        str_get = va_arg(vl, StrGetters*);
        search_str = va_arg(vl, char*);
    } else
    {
        get = va_arg(vl, Getters*);
        search_val = va_arg(vl, double);
    }
    cur = storage->first_pos;
    i = 0;
    while (cur != NULL)
    {
        if ((is_str && strcmp(str_get(cur), search_str) == 0) || (!is_str && search_val == get(cur)))
        {
            arr[i] = cur;
            i++;
        }
        cur = cur->next;
    }
    va_end(vl);
    return i;
}
val = find(storage, arr, true, str_getters[val - 1], search_string);
val = find(storage, arr, false, getters[val - 3], (double)search_val);
```
## Find обычная в две функции для каждого
```c
int find(Storage *storage, Smartphone** arr, Getters get, float search_val)
{
    Smartphone *cur;
    int i;
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

int find_str(Storage *storage, Smartphone** arr, StrGetters str_get, char* search_str)
{
    Smartphone *cur;
    int i;
    cur = storage->first_pos;
    i = 0;
    while (cur != NULL)
    {
        if ((strcmp(str_get(cur), search_str) == 0))
        {
            arr[i] = cur;
            i++;
        }
        cur = cur->next;
    }
    return i;
}
```

## Функция вставки (когда возможны разрывы в индексах)
```c
void insert_selected(Storage *storage, Smartphone *new, int index)
{
    Smartphone *cur;
    int found;

    found = 0;
    if (storage->size == 0){
        add_first(storage, new);
        storage->size++;
    }
    else if (storage->last_pos->index < index) // storage->size < index
    {
        cur = storage->last_pos;
//        new->index = storage->size + 1;
        add(storage, cur, new);
    } else
    {
        cur = storage->first_pos;
        while (cur)
        {
            if ((cur->next) && (cur->index < index && cur->next->index > index))
            {
                add(storage, cur, new);
                cur = NULL;
            } else if ((cur->next) && (cur->next->index == index))
            {
                add(storage, cur, new);
                cur = cur->next->next;
                cur->index++;
                cur = cur->next;
                found = 1;
            } else
            {
                if (!found) cur = cur->next;
                else
                {
                    cur->index++;
                    if (!(cur->next) || (cur->next && cur->next->index - cur->index > 1)) cur = NULL;
                    else cur = cur->next;
                }
            }
        }
    }
}
```

## Функция удаления (когда разрывы в индексах)
```c
void delete_selected(Storage *storage, int index)
{
    Smartphone *cur, *tmp;
    cur = storage->first_pos;

    // ищем что удалить
    if (storage->first_pos->index == index)
    {
        storage->first_pos = cur->next;
        if (cur->next) cur->next->prev = NULL;
        delete_position(cur);
        storage->size--;
    } else if (storage->size == 1 && cur->index == index)
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
    } else if (storage->last_pos->index < index || index < 1)
    {
        printf("\x1b[1;31mindex is out of list\x1b[0m\n");
    } else
    {
        while (cur != NULL)
        {
            if (cur->next->index == index)
            {
                tmp = cur->next;
                cur->next = tmp->next;
                tmp->next->prev = cur;
                delete_position(tmp);
                cur = NULL;
                storage->size--;
            } else
                cur = cur->next;
        }
    }
}
```

## Функция удаления всех выбранных брендов
```c
// НО ЭТА ХУЙНЯ УДАЛЯЕТ ВСЕ БРЕНДЫ, А НАДО ЛИ НАМ УДАЯЛТЬ ВСЕ БРЕНДЫ?
void delete_selected(Storage *storage, int index)
{
    Smartphone *cur, *tmp;
    Brand *brand;
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
            free(tmp);
            printf("Market is empty\n");
        } else if (storage->size <= index || storage->last_pos->brand == brand)
        {
            brand = storage->last_pos->brand;
            cur = storage->last_pos;
            storage->last_pos = cur->prev;
            storage->last_pos->next = NULL;
            delete_position(cur);
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
```