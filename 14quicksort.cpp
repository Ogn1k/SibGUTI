#include "fill_array.hpp"
#include <vector>
#include <math.h>

// int qsort(int *mas, int size, int &m, int &c) {
//     int i = 0, j = size - 1;
//     //int m=1, c=0;
//     m++;
//     int mid = mas[size / 2];
//     bool flag=false;
//     //Делим массив
//     do 
//     {

//         //c++;
//         //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
//         //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
//         while(mas[i] < mid) 
//         {
//             flag=true;
//             c++;
//             i++;
//         }
//         if(!flag) c++;
//         //В правой части пропускаем элементы, которые больше центрального
//         flag = false;
//         while(mas[j] > mid) 
//         {
//             flag=true;
//             c++;
//             j--;
//         }
//         if(!flag) c++;
//         //Меняем элементы местами
//         flag=false;
//         if (i <= j) 
//         {
//             //c++;
//             int tmp = mas[i];
//             mas[i] = mas[j];
//             mas[j] = tmp;

//             m+=3;
//             i++;
//             j--;
//         }
//         //if(i > j) c++;
//     } while (i <= j);


//     //Рекурсивные вызовы, если осталось, что сортировать
//     if(j > 0) 
//     {
//         //c++;
//         //"Левый кусок"
//         qsort(mas, j + 1, m, c);
//     }
//     //if(j < 0) c++;
//     if (i < size) 
//     {
//         //c++;
//         //"Првый кусок"
//         qsort(&mas[i], size - i, m, c);
//     }
//     //if(i > size) c++;
//     return m+c;
// }


void swap(int& a, int& b, int& swaps) {
    int temp = a;
    a = b;
    b = temp;
    swaps++;
}

// Функция для выбора опорного элемента (в данном случае - серединного элемента)
int choosePivot(int *arr, int low, int high, int& comparisons) {
    return arr[(low + high) / 2];
}

// Функция для разделения массива и возврата индекса опорного элемента
int partition(int *arr, int low, int high, int& comparisons, int& swaps) {
    int pivot = choosePivot(arr, low, high, comparisons);
    int i = low - 1;
    int j = high + 1;
    while (true) {
        do {
            i++;
            comparisons++;
        } while (arr[i] < pivot);
        do {
            j--;
            comparisons++;
        } while (arr[j] > pivot);
        if (i >= j)
            return j;
        swap(arr[i], arr[j], swaps);
    }
}

// Функция быстрой сортировки
void quickSort(int *arr, int low, int high, int& comparisons, int& swaps) {
    if (low < high) {
        int pi = partition(arr, low, high, comparisons, swaps);

        quickSort(arr, low, pi, comparisons, swaps);
        quickSort(arr, pi + 1, high, comparisons, swaps);
    }
}

// Функция для удобства вызова быстрой сортировки с подсчетом перестановок и сравнений
int qsort(int *arr, int size) {
    int comparisons = 0;
    int swaps = 0;
    quickSort(arr, 0, size - 1, comparisons, swaps);
    return comparisons + swaps;
}

int main() 
{ 

    int asize=100,bsize=200,csize=300,dsize=400,esize=500;
//664 5549 5549
    int tra=asize*log2(asize)+asize*log2(asize), tia=tra, tda=tra;
    int trb=bsize*log2(bsize)+bsize*log2(bsize), tib=trb, tdb=trb;
    int trc=csize*log2(csize)+csize*log2(csize), tic=trc, tdc=trc;
    int trd=dsize*log2(dsize)+dsize*log2(dsize), tid=trd, tdd=trd;
    int tre=esize*log2(esize)+esize*log2(esize), tie=tre, tde=tre;

    int a[100];
    int b[200];
    int c[300];
    int d[400];
    int e[500]; 


    int m=0, g=0;
    // FillRand(a, asize);
    // qsort(a, 100);

    // for(int i=0; i<asize; i++)
    // {
    //     std::cout << a[i] << " ";
    // }

    printTableHeader("qsort");
    printRow(asize, tda, tra, tia, qsort(FillDec(a, asize),asize), qsort(FillRand(a, asize), asize), qsort(FillInc(a, asize), asize));
    printRow(bsize, tdb, trb, tib, qsort(FillDec(b, bsize), bsize), qsort(FillRand(b, bsize), bsize), qsort(FillInc(b, bsize), bsize));
    printRow(csize, tdc, trc, tic, qsort(FillDec(c, 300), 300), qsort(FillRand(c, csize), csize), qsort(FillInc(c, csize), csize));
    printRow(dsize, tdd, trd, tid, qsort(FillDec(d, 400), 400), qsort(FillRand(d, dsize), dsize),  qsort(FillInc(d, dsize), dsize));
    printRow(esize, tde, tre, tie, qsort(FillDec(e, 500), 500), qsort(FillRand(e, esize), esize), qsort(FillInc(e, esize), esize));
    //std::cout << m << " " << g;
    return 0; 
}   

