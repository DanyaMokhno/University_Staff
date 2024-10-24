#ifndef LAB2_ARRAY_H
#define LAB2_ARRAY_H
#include <iostream>
#include <cwchar>

using namespace std;

class Set {
private:
    wchar_t* A;
    static const size_t n = 34;

public:
    wchar_t * operator [] (size_t _i){
        return &A[_i];
    }

    // объединение
    void operator |= (const Set& B) {
        size_t len_dst = wcslen(A);
        for (int i = 0; B.A && B.A[i] != '\0'; i++) {
            // note: проверка на то, чтобы символ не уже не содержался в строке, и на то, чтобы не содержался в строке C
            if (!wcschr(A, B.A[i])) {
                A[len_dst] = B.A[i];
                len_dst++;
            }
        }
        A[len_dst] = '\0';
    }
    Set operator|(const Set &B) const {
        Set C(*this);
        C |= B;
        return C;
    }

    // пересечение
    void operator /= (const Set& B) {
        const wchar_t * cA = A;
        int i, j;
        for (i = 0, j = 0; i <= wcslen(cA); i++) {
            if (!wcschr(B.A, cA[i])) {
                A[j] = cA[i];
                j++;
            }
        }
        A[j] = '\0';
    }

    Set operator/(const Set &B) const {
        Set C(*this);
        C /= B;
        return C;
    }

    void show(){
        wcout << "{" << A << "}" << endl;
    }

    // Конструктор копирования
    Set(const Set &other) : A(new wchar_t[n]) {
        wcscpy(A, other.A); // Копируем строку в выделенную память
    }

    Set(){
        A = new wchar_t[n];
    }
    Set(const wchar_t* _string): A(new wchar_t[n]){
        wcscpy(A, _string);
    }
    ~Set(){
        delete [] A;
    }
};

#endif //LAB2_ARRAY_H
