#include <iostream>
#include "sorts.hpp"
#include <random>

int main()
{
    const int N = 10000;
    std::vector<int> arr(N);

    Sample(arr);

    auto int_time = timer(bubbleSort, arr, N);
    std::cout << int_time << std::endl;

    double float_time = timer(Qsort, arr, N);
    std::cout << float_time << std::endl;

    double double_time = timer(inclusionSort, arr, N);
    std::cout << double_time << std::endl;

    return 0;
}