#include <vector>
#include <chrono>
#include <algorithm>
#include <random>


template<typename T>
void bubbleSort(std::vector<T>& arr)
{
    int i, j;
    for (i = 0; i < arr.size() - 1; i++)
        for (j = 0; j < arr.size() - i - 1; j++)
            if (arr[j] > arr[j + 1])
                std::swap(arr[j], arr[j + 1]);
}

template<typename T>
void inclusionSort(std::vector<T>& arr)
{
    int comp = 0;
    int move = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int value = arr[i];
        int index = i;
        while ((index > 0) && (arr[index - 1] > value))
        {

            arr[index] = arr[index - 1];
            index--;
        }
        arr[index] = value;
    }

}

int compvar(const void *one, const void *two)
{
    int a = *((int*)one);
    int b = *((int*)two);
    if (a<b)
       return -1;
    if (a == b)
       return 0;
    return 1;   

}

template<typename T>
void Qsort(std::vector<T>& arr)
{
    std::qsort(&arr[0], arr.size(), sizeof(int), compvar);    
}

template<typename T>
double timer(void(*sort_func)(std::vector<T>&), std::vector<T>& arr, int size)
{
    auto start = std::chrono::high_resolution_clock::now();
    sort_func(arr);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    return duration.count();
}

template<typename T>
void Sample(std::vector<T>& arr)
{
    std::mt19937 gen;
    gen.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937::result_type> d;
    for (int i = 0; i < arr.size(); ++i)
        arr[i] = d(gen);
}

