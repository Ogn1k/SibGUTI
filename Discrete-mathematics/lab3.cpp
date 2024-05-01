#include <iostream>
#include <locale.h>
#include <vector>
#include <sstream>
#include <algorithm>

template <typename T>
void quicksort(std::vector<T>& arr, int left, int right) {
    if (left >= right) {
        return;
    }

    int pivot = arr[(left + right) / 2];
    int i = left;
    int j = right;

    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Рекурсивные вызовы для левой и правой частей
    quicksort(arr, left, j);
    quicksort(arr, i, right);
}

bool isFloat(const std::string& str) 
{
    std::istringstream iss(str);
    float f;
    iss >> std::noskipws >> f; 
    return iss.eof() && !iss.fail();
}

float stringToFloat(const std::string& str) 
{
    std::istringstream iss(str);
    float result;
    iss >> std::noskipws >> result; 
    return result;
}

bool Next_p(std::vector<int>& arr) {
    int k = arr.size() - 2;
    while (k >= 0 && arr[k] >= arr[k + 1]) {
        k--;
    }
    if (k < 0) {
        return false; // Перестановки закончились
    }
    int l = arr.size() - 1;
    while (arr[k] >= arr[l]) {
        l--;
    }
    std::swap(arr[k], arr[l]);
    std::reverse(arr.begin() + k + 1, arr.end());
    return true;
}

int main()
{
    setlocale(LC_ALL, "");
    std::vector<int> a = {4, 2, 5, 1, 3};
    // std::string aa = "";
    
    // std::cout << "enter array\n";
    // while(aa != "end")
    // {
    //     std::cin >> aa;
    //     if(isFloat(aa))
    //     {
    //         a.insert(a.begin(), stringToFloat(aa));
    //     }
    // }
    //std::sort(a.begin(), a.end());
    quicksort(a, 0, a.size() - 1);
    //for(int n : a) std::cout << n << " ";
    std::cout << "\n";
    do
    {
        for(int n : a) std::cout << n << " ";
        std::cout << "\n";
    }
    while(Next_p(a));
    return 0;
}