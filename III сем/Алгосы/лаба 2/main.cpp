#include <iostream>
#include <chrono>
#include <cwchar>
#include "Array.h"
// #include "List.h"
// #include "Universum.h"
// #include "MachineWord.h"

using namespace std;

void Randomizer(wchar_t *arr, size_t power) {
    const wchar_t first_lower = L'а'; // Начало строчных букв
    const int UNIVERSE_SIZE = 34;
    bool used[UNIVERSE_SIZE] = {false};  // Массив для отслеживания использованных символов
    size_t i = 0;

    // Проверка, что power не больше размера вселенной возможных символов
    if (power >= UNIVERSE_SIZE) {
        power = UNIVERSE_SIZE-1;  // Ограничение на количество символов
    }

    while (i < power) {
        wchar_t new_char = (wchar_t)(first_lower + rand() % UNIVERSE_SIZE);

        // Проверяем, был ли символ использован и не равен ли он символу с разницей 32
        if (!used[new_char - first_lower] && (new_char - first_lower != 32)) {
            arr[i] = new_char;  // Если не был, добавляем его в массив
            used[new_char - first_lower] = true;  // Отмечаем как использованный
            i++;
        }
    }

    arr[i] = L'\0'; // Завершаем массив нулевым символом
}

int main() {
#ifndef __DARWIN_UNIX03__ // Устанавливаем локаль для macos
    wcout.imbue(locale("ru_RU.UTF-8"));
#else // Устанавливаем локаль для windows и linux
    setlocale(LC_ALL, "");
#endif
    const size_t len = 34;
    size_t power;
    wchar_t a[len], b[len], c[len], d[len];
    // получаем мощность множеств
    wcout << L"Введите мощность множеств:\n";
    cin >> power;
    // Инициализируем генератор случайных чисел
    srand(time(nullptr));
    Randomizer(a, power);
    Randomizer(b, power);
    Randomizer(c, power);
    Randomizer(d, power);
    wcout << "a: " << a << endl;
    wcout << "b: " << b << endl;
    wcout << "c: " << c << endl;
    wcout << "d: " << d << endl;

    Set A(a), B(b), C(c), D(d);
    auto t1 = chrono::high_resolution_clock::now( );
    // Вычисляем E = (A ∪ B ∪ D) \ C
    Set E = ((A | B) | D) / C;
    auto t2 = chrono::high_resolution_clock::now( );
    auto time_res = chrono::duration_cast<chrono::duration<double, micro>>(t2 - t1).count();

    cout << "E = (A ∪ B ∪ D) \\ C = ";
    E.show();
    // Вывод результата
    cout << "Время выполнения:\t" << time_res << " микросекунд" << endl;
    return 0;
}