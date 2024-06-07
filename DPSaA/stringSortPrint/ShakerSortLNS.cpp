#include <iostream>
#include <string>

void shakerSort(std::string& str) {
    int left = 0;
    int right = str.length() - 1;
    bool swapped;

    do {

        // Проход назад
        for (int i = right; i > left; --i) {
            std::cout << str;
            if (str[i] < str[i - 1]) {
                std::cout << " - " << str[i] << " " << str[i-1];
                std::swap(str[i], str[i - 1]);
                swapped = true;
            }
            std::cout << std::endl;
        }
        ++left;

        // Проход вперед
        swapped = false;
        for (int i = left; i < right; ++i) {
            std::cout << str;
            if (str[i] > str[i + 1]) {
                std::cout << " + " << str[i+1] << " " << str[i];
                std::swap(str[i], str[i + 1]);
                swapped = true;
            }
            std::cout << std::endl;
        }
        --right;

        

        // Вывод текущего состояния строки
        
    } while (swapped);
}
int main() {
    setlocale(LC_ALL, "Russian");
    std::string s = "федорушкин";
    std::cout << "Исходная строка: " << s << std::endl;
    shakerSort(s);
    std::cout << "Отсортированная строка: " << s << std::endl;
    return 0;
}