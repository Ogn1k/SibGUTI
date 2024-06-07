bool binSearch1(int *arr, int n, int X) {
    int L = 0; // Левая граница
    int R = n - 1; // Правая граница
    bool Найден = false;

    while (L <= R) {
        int m = (L + R) / 2; // Средний элемент

        if (arr[m] == X) {
            Найден = true;
            break;
        }

        if (arr[m] < X) {
            L = m + 1;
        } else {
            R = m - 1;
        }
    }

    return Найден;
}

bool binSearch2(int *arr, int n, int X) {
    int L = 0; // Левая граница (индекс 0 для массива)
    int R = n; // Правая граница (размер массива)

    while (L < R) {
        int m = (L + R) / 2; // Средний элемент

        if (arr[m] < X) {
            L = m + 1;
        } else {
            R = m;
        }
    }

    // Проверка, если элемент найден
    bool Найден = (L < n && arr[L] == X);
    return Найден;
}