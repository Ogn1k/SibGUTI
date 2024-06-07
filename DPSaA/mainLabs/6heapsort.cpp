#include "fill_array.hpp"

void swap(int *var1, int *var2)
{
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

void heap()
{
    j=2i;
    if(j>R)
    if((j<) && (arr[j+1]<= arr[j])) j=j+1;
    if(x <= arr[j])
    arr[i] = arr[j];
}

int heapSort(int* arr, int n)
{
    int L = n/2;
    while(L>0)
    {
        L=L-1;
    }
    int R=n;
    while(R>1)
    {
        swap(&arr[1], &arr[R]);
        R=R-1;
    }
}

int main()
{
    int asize=100,bsize=200,csize=300,dsize=400,esize=500;
    
    int tra=7425+4950, tia=0+4950, tda=14850+4950;
    int trb=29850+19900, tib=0+19900, tdb=59700+19900;
    int trc=67275+44850, tic=0+19900, tdc=134550+44850;
    int trd=119700+79800, tid=0+79800, tdd=239400+79800;
    int tre=187125+124750, tie=0+124750, tde=374250+124750;

	int a[100];
	int b[200];
	int c[300];
	int d[400];
	int e[500]; 

    printTableHeader();
    printRow(asize, tra, tia, tda, heapSort(FillDec(a, asize), asize), heapSort(FillRand(a, asize), asize), heapSort(FillInc(a, asize), asize));
    printRow(bsize, tdb, trb, tib, heapSort(FillDec(b, bsize), bsize), heapSort(FillRand(b, bsize), bsize), heapSort(FillInc(b, bsize), bsize));
    printRow(csize, tdc, trc, tic, heapSort(FillDec(c, 300), 300), heapSort(FillRand(c, csize), csize), heapSort(FillInc(c, csize), csize));
    printRow(dsize, tdd, trd, tid, heapSort(FillDec(d, 400), 400), heapSort(FillRand(d, dsize), dsize),  heapSort(FillInc(d, dsize), dsize));
    printRow(esize, tde, tre, tie, heapSort(FillDec(e, 500), 500), heapSort(FillRand(e, esize), esize), heapSort(FillInc(e, esize), esize));
	
}