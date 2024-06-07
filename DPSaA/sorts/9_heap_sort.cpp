#include <utility>

void heapify(int *arr, int l, int r)
{
    //int l = L+1;
    char x = arr[l]; int i = l;
    while(true)
    {
        int j = 2*i;
        if(j>r) break;
        if(j<r && arr[j+1]<=arr[j]) j++;
        if(x<=arr[j]) break;
        arr[i]=arr[j];
        i=j;
    }
    arr[i]=x;
}

int HeapSort(int *arr, int size) {
    int m = 0, c = 0;
    for (int l = size / 2; l >= 0; l--)
        heapify(arr, l, size - 1);
    int r = size - 1;
    while (r > 0) {
        std::swap(arr[0], arr[r--]);
        //m += 3;
        heapify(arr, 0, r);
    }
    return m + c;
}