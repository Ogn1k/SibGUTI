#include "fill_array.hpp"
#include <concepts>
#include <math.h>
template <class T> void build_heap(T &arr, size_t l, size_t r, size_t &m, size_t &c) {
    auto x = arr[l];
    size_t i = l;
    while (true) {
        size_t j = 2 * i;
        if (j > r)
            break;
        if (j < r and arr[j + 1] <= arr[j])
            j++;
        c++;
        if (x <= arr[j]) {
            c++;
            break;
        }
        c++;
        arr[i] = arr[j];
        m++;
        i = j;
    }
    arr[i] = x;
    m += 2;
}

size_t HeapSort(int *arr, int size) {
    size_t m = 0, c = 0;
    for (long long l = size / 2; l >= 0; l--)
        build_heap(arr, l, size - 1, m, c);
    size_t r = size - 1;
    while (r > 0) {
        std::swap(arr[0], arr[r--]);
        m += 3;
        build_heap(arr, 0, r, m, c);
    }
    return m + c;
}

int main() 
{ 

    int asize=100,bsize=200,csize=300,dsize=400,esize=500;

    //(asize*log2(asize)+6.5*500-4)+(2*asize*log2(asize)+asize+2)
    int tra=(asize*log2(asize)+6.5*asize-4)+(2*asize*log2(asize)+asize+2), tia=tra, tda=tra;
    int trb=(bsize*log2(bsize)+6.5*bsize-4)+(2*bsize*log2(bsize)+bsize+2), tib=trb, tdb=trb;
    int trc=(csize*log2(csize)+6.5*csize-4)+(2*csize*log2(csize)+csize+2), tic=trc, tdc=trc;
    int trd=(dsize*log2(dsize)+6.5*dsize-4)+(2*dsize*log2(dsize)+dsize+2), tid=trd, tdd=trd;
    int tre=(esize*log2(esize)+6.5*esize-4)+(2*esize*log2(esize)+esize+2), tie=tre, tde=tre;

    int a[100];
    int b[200];
    int c[300];
    int d[400];
    int e[500]; 

    // FillRand(a, asize);
    // HeapSort(a, 100);

    // for(int i=0; i<asize; i++)
    // {
    //     std::cout << a[i] << " ";
    // }

    printTableHeader("HeapSort");
    printRow(asize, tda, tra, tia, HeapSort(FillDec(a, asize), asize), HeapSort(FillRand(a, asize), asize), HeapSort(FillInc(a, asize), asize));
    printRow(bsize, tdb, trb, tib, HeapSort(FillDec(b, bsize), bsize), HeapSort(FillRand(b, bsize), bsize), HeapSort(FillInc(b, bsize), bsize));
    printRow(csize, tdc, trc, tic, HeapSort(FillDec(c, 300), 300), HeapSort(FillRand(c, csize), csize), HeapSort(FillInc(c, csize), csize));
    printRow(dsize, tdd, trd, tid, HeapSort(FillDec(d, 400), 400), HeapSort(FillRand(d, dsize), dsize),  HeapSort(FillInc(d, dsize), dsize));
    printRow(esize, tde, tre, tie, HeapSort(FillDec(e, 500), 500), HeapSort(FillRand(e, esize), esize), HeapSort(FillInc(e, esize), esize));
    
    return 0; 
}   