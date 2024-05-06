#include <iostream>
#include <string>

void shellSort(std::string& str) {
    int n = str.length();
    int h = 1;

    // Вычисляем начальное значение h
    while (h < n / 3) {
        h = 3 * h + 1;
    }

    while (h >= 1) {
        // Сортировка вставками для текущего значения h
        for (int i = h; i < n; ++i) {
            char key = str[i];
            int j = i;

            while (j >= h && str[j - h] > key) {
                str[j] = str[j - h];
                j -= h;
            }

            str[j] = key;
        }

        // Выводим текущее состояние строки после итерации
        std::cout << "Итерация с h = " << h << ": " << str << std::endl;

        // Уменьшаем значение h
        h /= 3;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string input = "курапова";
    std::cout << "Исходная строка: " << input << std::endl;   
    

    shellSort(input);

    std::cout << "Отсортированная строка: " << input << std::endl;

    return 0;
}