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
    int mid = left + (right - left) / 2;
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

int main() {
    setlocale(LC_ALL, "");
    string str = "федорушкинст";
    cout << "Original string: " << str << endl;
    quicksort(str);
    cout << "Sorted string: " << str << endl;
    return 0;
}