void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int quicksort(int *arr, int L, int R)
{
    int i = L, j = R;
    int x = arr[L]; // Опорный элемент

    // Основной цикл
    while (i <= j) {
        while (arr[i] < x) i++;
        while (arr[j] > x) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    // Рекурсивные вызовы для левой и правой частей
    if (L < j) quicksort(arr, L, j);
    if (i < R) quicksort(arr, i, R);
}
