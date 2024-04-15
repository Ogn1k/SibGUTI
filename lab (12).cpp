#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

// ������� ��� ��������� ������� ���������� ����������
template <typename T>
double timer(void (*sort_func)(T*, int), T* arr, int size) {
    auto start = std::chrono::high_resolution_clock::now();
    sort_func(arr, size);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

// ������� ��� ���������� ������� ����� �����
void integer_sort(int* arr, int size) {
    std::sort(arr, arr + size);
}

// ������� ��� ���������� ������� ������������ �����
void float_sort(float* arr, int size) {
    std::sort(arr, arr + size);
}

int main() {
    const int N = 1000000; // ���������� ��������� � �������
    std::vector<int> int_array(N);
    std::vector<float> float_array(N);

    // ���������� �������� ���������� ����������
    for (int i = 0; i < N; ++i) {
        int_array[i] = rand() % 1000;
        float_array[i] = static_cast<float>(rand()) / RAND_MAX;
    }

    // ��������� ������� ���������� ������� ����� �����
    double int_time = timer(integer_sort, int_array.data(), N);
    std::cout << "����� ���������� ����� �����: " << int_time << " ������" << std::endl;

    // ��������� ������� ���������� ������� ������������ �����
    double float_time = timer(float_sort, float_array.data(), N);
    std::cout << "����� ���������� ������������ �����: " << float_time << " ������" << std::endl;

    return 0;
}