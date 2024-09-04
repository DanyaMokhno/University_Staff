#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Dictionary
{
    char first_letter;  // первая буква слова
    char *word;         // указатель на слово
    Dictionary *left;   // указатель на правый лист дерева
    Dictionary *right;  // указатель на левый лист дерева
};

// функция заполнения дерева элементами
void fill_dict(Dictionary **dict);

// функция добавления элемента в дерево
void add_word(Dictionary **node, char key_letter, char *word);

// функция поиска и вывода нужных элементов в дереве
void search_all(Dictionary *node, char key_letter, bool *found);

// функция поиска и вывода нужных элементов путём прямого обхода
void search_all_preorder(Dictionary *node, char key_letter);

// функция поиска и вывода нужных элементов путём центрированного обхода
void search_all_inorder(Dictionary *node, char key_letter);

// функция поиска и вывода нужных элементов путём обратного обхода
void search_all_postorder(Dictionary *node, char key_letter);

// функция удаления дерева
void delete_dict(Dictionary *node);

int main()
{
    Dictionary *Library = nullptr;  // собственно дерево
    char letter;                    // буква с которой будут начинаться искомые слова
    bool found;                     // флаги для обозначения того что число найдено и того что дерево заполнено

    found = false;                  // устанавливаем значение флага по умолчанию ложь
    fill_dict(&Library);      	    // заполняем массив, передав в функцию указатель на корень дерева и устанавливаем флаг заполненного дерева
    if (Library)                    // если дерево не пустое
    {
        cout << "input letter: ";
        cin >> letter;                   	    // запрашиваем число
        found = false;                   	    // устанавливаем значение флага по умолчанию ложь
        cout << "\x1b[1;35mSearch:\x1b[0m" << endl; // \x1b[35...\x1b[0m – это "ANSI escape code" он придаёт формат и цвет выводимому в консоль тексту
                                                    // https://habr.com/ru/articles/94647/
        search_all(Library, letter,&found);    	    // выполняем поиск и вывод найденных слов, передаём указатель на указатель на словарь,
                                                    // чтобы установить в функции его значение
        // в последующие функции поиска и вывода элементов флаг не передаём, потому, что результат у них тот же, что и у предыдущей
        if (found)                                  // если нашли слов на нужную букву, вызываем остальные функции поиска
        {
            cout << endl << "\x1b[1;35mPreorder Traversal:\x1b[0m" << endl;
            search_all_preorder(Library, letter);   				// выполняем поиск и вывод найденных слов с помощью прямого обхода
            cout << endl << "\x1b[1;35mInorder Traversal:\x1b[0m" << endl;
            search_all_inorder(Library,letter);                    		// выполняем поиск и вывод найденных слов с помощью центрированного обхода
            cout << endl << "\x1b[1;35mPostorder Traversal:\x1b[0m" << endl;
            search_all_postorder(Library, letter);  				// выполняем поиск и вывод найденных слов с помощью обратного обхода
        } else cout << "\x1b[31mno word starts with this letter\x1b[0m";        // если не нашли слов на нужную букву, выводим сообщение
        delete_dict(Library);                               			// удаляем дерево
    }
    return 0;
}

/*
 * Функции fill_dict и add_word принимают указатель на указатель на структуру Dictionary,
 * потому что она должна изменять значение указателя на словарь. В C++ аргументы передаются по значению,
 * что означает, что функции передается копия значения аргумента. Если мы передадим просто указатель на Dictionary,
 * функция получит копию этого указателя и сможет изменить только копию, а не сам указатель, который мы передали.
 * Чтобы функция могла изменить сам указатель, нужно передать указатель на этот указатель. Это позволит функции изменять значение самого указателя,
 * а не только его копии. В результате, если мы выделим память для структуры Dictionary внутри функции add_word (например, когда создаем новый узел дерева),
 * изменения будут отражены в указателе на словарь, который был передан в функцию.
 * */
void fill_dict(Dictionary **dict)   // принимаем указатель на указатель на корень дерева
{
    ifstream file;                  // объявляем объект файла
    char *tmp_string;               // указатель на строку для хранения слова из файла
    char filename[40];              // строка для хранения названия файла
    size_t len;                     // длинна строки из файла

    cout << "input the filename" << endl;
    cin.getline(filename, 40);   // получаем название файла
    file.open(filename);            // открываем файл
    if (file.is_open())                // если файл отрылся
    {
        while (!file.eof())            // пока не дошли до конца файла
        {
            tmp_string = new char[50];      // выделяем память под строку
            file >> tmp_string;             // считываем строку из файла
            len = strlen(tmp_string);       // считаем длину строки
            if (!(tmp_string[len - 1] >= 'A' && tmp_string[len - 1] <= 'Z') ||
                !(tmp_string[len - 1] >= 'a' && tmp_string[len - 1] <= 'z'))    // если последний символ слова это не буква
                tmp_string[len - 1] = '\0';                                     // то заменяем его на символ окончания строки
            add_word(dict, tmp_string[0], tmp_string);     // добавляем слово в дерево
        }
        file.close(); // закрываем файл
    } else                                  		   // если файл не открылся
        cout << "\x1b[31mcheck file existence\x1b[0m\n";   // выводим сообщение
}

void add_word(Dictionary **node, char key_letter, char *word)
{
    if (*node) // если узел не пустой
    {
        if (!strcmp(word, (*node)->word)) // сравниваем переданное слово и имеющееся в дереве слово, если в дереве слово уже есть,
        {
            delete word; //  освобождаем выделенную под слово память
            return;      // возвращаемся из функции
        }
        (key_letter < (*node)->first_letter) ? add_word(&((*node)->left), key_letter, word) : add_word( &((*node)->right), key_letter, word); // если первая буква переданного слова, по алфавиту идёт раньше,
                                                                                                                                              // чем первая буква строки текущего узла,
                                                                                                                                              // то переходим к левому узлу, в ином случае к правому
    } else  // если узел пустой
    {
        *node = new Dictionary;                 // выделяем память под новый узел
        (*node)->first_letter = key_letter;     // присваиваем полю первой буквы слова, первую букву слова
        (*node)->word = word;                   // присваиваем указателю на слово, адрес из переданного указателя на слово
    }
}

// поиск элементов (работает за O(log(n))
void search_all(Dictionary *node, char key_letter, bool *found)
{
    if (node == nullptr) return;                // если узел пустой, возвращаемся
    else if (node->first_letter == key_letter)  // если слово начинается с той же буквы
    {
        cout << node->word << " ";              // выводим слово
        *found = true;                          // флаг найденного слова ставим true
    }
    (key_letter < node->first_letter) ? search_all(node->left, key_letter, found) : search_all(node->right, key_letter, found);	// если первая буква переданной строки идёт раньше,
}                                                                                                                               // чем первая буква строки текущего узла,
                                                                                                                                // то переходим к левому узлу, в ином случае к правому

/*
 * Обход дерева — последовательное единоразовое посещение всех вершин дерева.
 * Прямой обход (КЛП): корень → левое поддерево → правое поддерево
 * Центрированный обход (ЛКП): левое поддерево → корень → правое поддерево
 * Обратный обход (ЛПК): левое поддерево → правое поддерево → корень
 * */

// прямой обход
void search_all_preorder(Dictionary *node, char key_letter)
{
    if (node == nullptr) return;                                            	// если узел пустой, возвращаемся
    else if (node->first_letter == key_letter) cout << node->word << " ";	// если слово начинается с той же буквы, выводим его
    search_all_preorder(node->left, key_letter);				// переходим к левому узлу
    search_all_preorder(node->right, key_letter);                     		// переходим к правому узлу
}

// Центрированный обход
void search_all_inorder(Dictionary *node, char key_letter)
{
    if (node == nullptr) return;                                         // если узел пустой, возвращаемся
    search_all_inorder(node->left, key_letter);                   	// переходим к левому узлу
    if (node->first_letter == key_letter) cout << node->word << " ";    // если слово начинается с той же буквы, выводим его
    search_all_inorder(node->right, key_letter);                  	// переходим к правому узлу
}

// Обратный обход
void search_all_postorder(Dictionary *node, char key_letter)
{
    if (node == nullptr) return;                                        // если узел пустой, возвращаемся
    search_all_postorder(node->left, key_letter);                 	// переходим к левому узлу
    search_all_postorder(node->right, key_letter);                	// если слово начинается с той же буквы, выводим его
    if (node->first_letter == key_letter) cout << node->word << " ";    // переходим к правому узлу
}

void delete_dict(Dictionary *node)
{
    if (node == nullptr) return;      	// если узел пуст, возвращаемся
    delete_dict(node->left);    	// если переходим к левому узлу
    delete_dict(node->right);   	// переходим к правому узлу
    delete[] node->word;              // освобождаем память из-под слова
    delete node;                      // освобождаем память из-под узла
}