#ifndef LAB2_UNIVERSUM_H
#define LAB2_UNIVERSUM_H

#include <iostream>

using namespace std;

class Set {
private:
    static const size_t n = 34;
    bool A[n];

// Функция для отображения строки на вектор битов
    void stringToUniverse(const wchar_t *str) {
        // Инициализация вектора битов
        for (int i = 0; i < n; ++i)
            A[i] = false;

        // Устанавливаем бит для каждой буквы из строки
        for (int i = 0; str[i]; ++i) {
            // Индекс буквы относительно 'а'
            int index = str[i] - L'а';
            if (index >= 0 && index < n) {
                A[index] = true;
            }
        }
    }

public:
    bool operator[](size_t _i) const {
        return A[_i];
    }

    // объединение
    void operator|=(const Set &B) {
        for (int i = 0; i < n; ++i)
            A[i] = A[i] || B[i];
    }

    Set operator|(const Set &B) const {
        Set C(*this);
        C |= B;
        return C;
    }

    // пересечение
    void operator/=(const Set &B) {
        for (int i = 0; i < n; ++i)
            A[i] = A[i] && !B[i];
    }

    Set operator/(const Set &B) const {
        Set C(*this);
        C /= B;
        return C;
    }

    void show() {
        int j = 0;
        wchar_t str[n];
        for (int i = 0; i < n; ++i) {
            if (A[i]) {
                str[j] = (wchar_t) (L'а' + i);
                j++;
            }
        }
        str[j] = '\0';
        wcout << "{" << str << "}" << endl;
    }

    Set() {

    }

    Set(const wchar_t *_string) {
        stringToUniverse(_string);
    }
};

#endif //LAB2_UNIVERSUM_H
