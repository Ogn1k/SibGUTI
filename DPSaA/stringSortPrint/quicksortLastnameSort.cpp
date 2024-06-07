#include <iostream>
#include <string>

using namespace std;

void printIteration(const string& str, int left, int right, int pivotIndex) {
    cout << "Iteration: ";
    for (int i = 0; i < str.length(); ++i) {
        if (i == left || i == right || i == pivotIndex) {
            cout << "[" << str[i] << "] ";
        } else {
            cout << str[i] << " ";
        }
    }
    cout << endl;
}

int partition(string& str, int left, int right) {
    int mid = left;
    char pivot = str[mid];
    int i = left - 1;
    int j = right + 1;
    
    while (true) {
        do {
            i++;
        } while (str[i] < pivot);

        do {
            j--;
        } while (str[j] > pivot);

        if (i >= j)
            return j;

        swap(str[i], str[j]);
        printIteration(str, left, right, mid);
    }
}

void quicksort(string& str, int left, int right) {
    if (left < right) {
        int pivotIndex = partition(str, left, right);
        quicksort(str, left, pivotIndex);
        quicksort(str, pivotIndex + 1, right);
    }
}

void quicksort(string& str) {
    quicksort(str, 0, str.length() - 1);
}

void quickSortss(std::string& arr, int L, int R) {
    int i = L;
    int j = R;
    char x = arr[L]; // Выбираем опорный элемент, здесь берём средний элемент

    // Основная часть алгоритма
    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j) {
            std::cout << arr << std::endl;
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Рекурсивная сортировка частей
    if (L < j) {
        std::cout << "LL: " << L << " j: " << j << " R: " << R << " i: " << i << std::endl;
        quickSortss(arr, L, j);
    }
    if (i < R) {
        std::cout << "RL: " << L << " j: " << j << " R: " << R << " i: " << i << std::endl;
        quickSortss(arr, i, R);
    }
}


int main() {
    setlocale(LC_ALL, "Russian");
    string str = "федорушкин";
    cout << "Original string: " << str << endl;
    //quicksort(str);
    quickSortss(str, 0, str.length()-1);
    cout << "Sorted string: " << str << endl;
    return 0;
}