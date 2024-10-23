#ifndef LAB2_LIST_H
#define LAB2_LIST_H

#include <iostream>

using namespace std;

struct List {
    wchar_t letter = L'\0';
    List *next = nullptr;
};

class Set {
private:
    static const size_t n = 34;
    List *A_list = nullptr;

    // Функция для проверки, содержится ли символ в списке
    bool contains(const List *list, wchar_t symbol) {
        while (list) {
            if (list->letter == symbol) {
                return true;
            }
            list = list->next;
        }
        return false;
    }

// Функция для добавления символа в список (если его нет)
    void add_List(wchar_t symbol) {
        if (!contains(A_list, symbol)) {
            List *new_List = new List;
            new_List->letter = symbol;
            new_List->next = A_list;
            A_list = new_List;
        }
    }

// Функция для преобразования строки в список
    void string_to_list(const wchar_t *str) {
        size_t len = wcslen(str);
        for (size_t i = 0; i < len; i += 1) {
            wchar_t symbol = str[i];
            add_List(symbol);
        }
    }

public:
    // объединение
    void operator|=(const Set &B) {
        List *B_list = B.A_list;
        while (B_list) {
            if (!contains(A_list, B_list->letter)) {
                add_List(B_list->letter);
            }
            B_list = B_list->next;
        }
    }

    Set operator|(const Set &B) const {
        Set C(*this);
        C |= B;
        return C;
    }

    // пересечение
    void operator/=(const Set &B) {
        List *prev = nullptr, *cur = A_list;
        List *B_list = B.A_list;

        while (cur) {
            // Если буква A находится в B, удаляем её из A
            if (contains(B_list, cur->letter)) {
                if (prev) {
                    prev->next = cur->next; // Пропускаем текущий узел
                    delete cur;             // Удаляем текущий узел
                    cur = prev->next;       // Переходим к следующему узлу
                } else {
                    // Обновляем голову, если удаляем первый узел
                    List *temp = cur;        // Сохраняем текущий узел для удаления
                    A_list = cur->next;          // Перемещаем голову на следующий узел
                    cur = A_list;                // Обновляем текущий до головы
                    delete temp;             // Удаляем старую голову
                }
            } else {
                prev = cur;                  // Перемещаем prev на текущий узел
                cur = cur->next;             // Переходим к следующему узлу
            }
        }
    }

    Set operator/(const Set &B) const {
        Set C(*this);
        C /= B;
        return C;
    }

    void show() const {
        int i = 0;
        wchar_t str[n];
        List *temp = A_list;
        while (temp) {
            str[i] = temp->letter;
            i++;
            temp = temp->next;
        }
        str[i] = '\0';
        wcout << "{" << str << "}" << endl;
    }

    // Конструктор копирования
    Set(const Set &other) : A_list(nullptr) {
        List *current = other.A_list;
        while (current) {
            add_List(current->letter);
            current = current->next;
        }
    }

    Set() :A_list(nullptr) {};

    Set(const wchar_t *_string) :A_list(nullptr){
        string_to_list(_string);
    }

    ~Set() {
        while (A_list) {
            List *temp = A_list;
            A_list = A_list->next;
            delete temp;
        }
    }
};

#endif //LAB2_LIST_H
