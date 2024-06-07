#include <iostream>
#include <string>

void insertionSortWithVisualization(std::string& str) {
    int n = str.length();
    for (int i = 1; i < n; ++i) {
        char key = str[i];
        int j = i - 1;

        // Move elements of str[0..i-1] that are greater than key
        // to one position ahead of their current position
        while (j >= 0 && str[j] > key) {
            str[j + 1] = str[j];
            std::cout << "Iteration " << i << ": " << str << " " << str[i] << " " << str[j] << std::endl;
            --j;
        }
        str[j + 1] = key;

        // Print the current state of the string
        }
}

int main() {
    setlocale(LC_ALL, "Russian");
    std::string inputString = "федорушкин";
    std::cout << "Исходная строка: " << inputString << std::endl;   
    insertionSortWithVisualization(inputString);

    std::cout << "Отсортированная строка: " << inputString << std::endl;
    return 0;
}
