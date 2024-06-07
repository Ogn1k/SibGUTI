#include <iostream>
#include <string>

void bubbleSort(std::string &str) {
    int n = str.length();
    int iter = 0;
    for (int i = 0; i <= n-1; i++) {
        for (int j = n; j >= i+1; j--) {
            if (str[j] < str[j-1]) {
                // меняем местами str[j] и str[j+1]
                std::swap(str[j], str[j-1]);
            }
            std::cout << "Итерация " << iter++ << ": " << str << std::endl;
        }
        // выводим строку после каждой итерации
        
    }
}

int main() 
{
    setlocale(LC_ALL, "Russian");
    std::string str = "федорушкин";
    std::cout << "Исходная строка: " << str << std::endl;
    bubbleSort(str);
    std::cout << "Отсортированная строка: " << str << std::endl;
    return 0;
}