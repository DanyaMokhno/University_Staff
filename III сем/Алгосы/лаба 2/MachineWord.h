#ifndef LAB2_MACHINEWORD_H
#define LAB2_MACHINEWORD_H

#include <iostream>

using namespace std;

class Set {
private:
    static const size_t n = 34;
    unsigned long long A = 0;

// Функция отображения символа в позицию бита
    int charToBitIndex(wchar_t ch) {
        if (ch >= L'а' && ch <= L'ё') {
            return ch - L'а'; // Индекс для русских букв
        }
        return -1; // Неизвестный символ
    }

// Функция для отображения строки на машинное слово (64-битное число)
    void strToWord(const wchar_t *str) {
        for (int i = 0; str[i]; ++i) {
            int bitIndex = charToBitIndex(str[i]);
            if (bitIndex != -1) {
                A |= (1ULL << bitIndex); // Устанавливаем бит для символа
            }
        }
    }

public:
    // объединение
    void operator|=(const Set &B) {
        A |= B.A;
    }

    Set operator|(const Set &B) const {
        Set C(*this);
        C |= B;
        return C;
    }

    // пересечение
    void operator/=(const Set &B) {
        A = A & ~B.A;
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
            if (A & (1ULL << i)) {
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
        strToWord(_string);
    }
};

#endif //LAB2_MACHINEWORD_H
