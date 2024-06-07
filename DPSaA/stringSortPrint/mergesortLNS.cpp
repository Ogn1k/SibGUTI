#include <iostream>
#include <vector>
#include <string>

void merge(std::string& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    std::string L, R;

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(std::string& arr) {
    int n = arr.size();
    for (int curr_size = 1; curr_size < n; curr_size *= 2) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = std::min(left_start + curr_size - 1, n - 1);
            int right_end = std::min(left_start + 2 * curr_size - 1, n - 1);

            merge(arr, left_start, mid, right_end);

            // Print the current iteration
            std::cout << "Iteration: ";
            for (int i = left_start; i <= right_end; i++)
                std::cout << arr[i] << " ";
            std::cout << std::endl;
        }
    }
}

int main() {
    setlocale(LC_ALL, "");
    std::string arr = "федорушкинст";
    int n = arr.length();

    std::cout << "Original array: ";
    for (const auto& s : arr)
        std::cout << s << " ";
    std::cout << std::endl;

    mergeSort(arr);

    std::cout << "Sorted array: ";
    for (const auto& s : arr)
        std::cout << s << " ";
    std::cout << std::endl;

    return 0;
}