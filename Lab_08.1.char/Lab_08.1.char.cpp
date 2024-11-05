#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Функція для підрахунку кількості пар сусідніх символів "aa", "bb" або "cc"
int Count(const char* str) {
    int k = 0;
    while (*str && *(str + 1)) {
        if ((*str == 'a' && *(str + 1) == 'a') ||
            (*str == 'b' && *(str + 1) == 'b') ||
            (*str == 'c' && *(str + 1) == 'c')) {
            k++;
            str += 2; // Пропускаємо знайдену пару
        }
        else {
            str++;
        }
    }
    return k;
}

// Функція для заміни кожної пари сусідніх символів "aa", "bb" або "cc" на "***"
char* Change(char* str) {
    size_t len = strlen(str);
    char* tmp = new char[len * 3 / 2 + 1]; // Виділення достатнього обсягу пам'яті
    tmp[0] = '\0'; // Ініціалізація порожнього рядка

    while (*str) {
        if ((*str == 'a' && *(str + 1) == 'a') ||
            (*str == 'b' && *(str + 1) == 'b') ||
            (*str == 'c' && *(str + 1) == 'c')) {
            strcat(tmp, "***"); // Додаємо "***" замість пари
            str += 2; // Пропускаємо пару
        }
        else {
            size_t len = strlen(tmp);
            tmp[len] = *str; // Додаємо поточний символ до `tmp`
            tmp[len + 1] = '\0';
            str++;
        }
    }
    return tmp;
}

int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    // Виведення кількості пар
    cout << "String contained " << Count(str) << " groups of 'aa', 'bb' or 'cc'" << endl;

    // Заміна пар
    char* dest = Change(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    delete[] dest; // Очищення пам'яті
    return 0;
}
