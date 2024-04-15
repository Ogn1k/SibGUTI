#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// Функция для измерения времени выполнения сортировки
template <typename T>
double timer(void (*sort_func)(T*, int), T* arr, int size) {
    auto start = std::chrono::high_resolution_clock::now();
    sort_func(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

// Функция для сортировки массива целых чисел
void integer_sort(int* arr, int size) {
    std::sort(arr, arr + size);
}

// Функция для сортировки массива вещественных чисел
void float_sort(float* arr, int size) {
    std::sort(arr, arr + size);
}

int main() {
    const int N = 1000000; // Количество элементов в массиве
    std::vector<int> int_array(N);
    std::vector<float> float_array(N);

    // Заполнение массивов случайными значениями
    for (int i = 0; i < N; ++i) {
        int_array[i] = rand() % 1000;
        float_array[i] = static_cast<float>(rand()) / RAND_MAX;
    }

    // Измерение времени сортировки массива целых чисел
    double int_time = timer(integer_sort, int_array.data(), N);
    std::cout << "Время сортировки целых чисел: " << int_time << " секунд" << std::endl;

    // Измерение времени сортировки массива вещественных чисел
    double float_time = timer(float_sort, float_array.data(), N);
    std::cout << "Время сортировки вещественных чисел: " << float_time << " секунд" << std::endl;

    return 0;
}