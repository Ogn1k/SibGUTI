#include <iostream>
#include <string>
#include <vector>

using namespace std;

void heapify(vector<char>& arr, int n, int i) {
    int largest = i; // Инициализируем наибольший элемент как корень
    int left = 2 * i + 1; // левый = 2*i + 1
    int right = 2 * i + 2; // правый = 2*i + 2

    // Если левый дочерний элемент больше корня
    if (left < n && arr[left] < arr[largest])
        largest = left;

    // Если правый дочерний элемент больше, чем самый большой элемент на данный момент
    if (right < n && arr[right] < arr[largest])
        largest = right;

    // Если самый большой элемент не корень
    if (largest != i) {
        for (char c : arr)
            cout << c;
        cout << " heapify" << endl;
        swap(arr[i], arr[largest]);

        // Рекурсивно преобразуем в двоичную кучу затронутое поддерево
        heapify(arr, n, largest);
    }
}

void heapsort(vector<char>& arr) {
    int n = arr.size();

    // Построение кучи (перегруппировка массива)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Один за другим извлекаем элементы из кучи
    for (int i = n - 1; i > 0; i--) {
        // Перемещаем текущий корень в конец
        swap(arr[0], arr[i]);

        // Выводим текущую итерацию
        for (char c : arr)
            cout << c ;
        cout << " sort" << endl;

        // вызываем процедуру heapify на уменьшенной куче
        heapify(arr, i, 0);
    }
}

int main() {
        setlocale(LC_ALL, "Russian");
    string str = "федорушкинст";
    vector<char> arr(str.begin(), str.end());

    cout << "Исходная строка: " << str << endl;
    heapsort(arr);
    cout << "Отсортированная строка: ";
    for (char c : arr)
        cout << c ;
    cout << endl;

    return 0;
}