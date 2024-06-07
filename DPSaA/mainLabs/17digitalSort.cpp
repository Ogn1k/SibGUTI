#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include "fill_array.hpp"

// ������� ��� �������� ������������ � ���������
// int digitalSort(int arr[], int n) {
//     int swaps = 0;
//     //int n = arr.size();
//     int output[n];
//     int maxVal /*= *std::max_element(arr.begin(), arr.end())*/;
//     for(int i=0;i<n;i++)
//         if(arr[i]>maxVal)
//             maxVal=arr[i];

//     for (int exp = 1; maxVal / exp > 0; exp *= 10) {
//         std::vector<int> count(10, 0);

//         // ������� ���������� ��������� ����
//         for (int i = 0; i < n; ++i) {
//             count[(arr[i] / exp) % 10]++;
//         }

//         // ���������� ��������
//         for (int i = 1; i < 10; ++i) {
//             count[i] += count[i - 1];
//         }

//         // ���������� ���������������� �������
//         for (int i = n - 1; i >= 0; --i) {
//             output[count[(arr[i] / exp) % 10] - 1] = arr[i];
//             count[(arr[i] / exp) % 10]--;
//         }

//         // ����������� ���������������� ������� ������� � ��������
//         for (int i = 0; i < n; ++i) {
//             arr[i] = output[i];
//             swaps++; // ����������� ������� ������������
//         }
//     }
//     return swaps;
// }

// int digitalSortSC(int arr[], int n)
// {
//     int swaps=0;
//     return digitalSort(arr, n);
// }

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp, double &swaps)
{

    int output[n];
    int i, count[10] = { 0 };

    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
        swaps += (double)1/3;
    }
        
}

double radixsort(int arr[], int n)
{

    int m = getMax(arr, n);
    double swaps = 0;

    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp, swaps);
    return std::round(swaps);
}

int main() 
{
    int asize=100,bsize=200,csize=300,dsize=400,esize=500;

    int tra=asize, tia=tra, tda=tra;
    int trb=bsize, tib=trb, tdb=trb;
    int trc=csize, tic=trc, tdc=trc;
    int trd=dsize, tid=trd, tdd=trd;
    int tre=esize, tie=tre, tde=tre;

    int a[100];
    int b[200];
    int c[300];
    int d[400];
    int e[500]; 

    printTableHeader("digitalSort");
    printRow(asize, tda, tra, tia, radixsort(FillDec(a, asize), asize), radixsort(FillRand(a, asize), asize), radixsort(FillInc(a, asize), asize));
    printRow(bsize, tdb, trb, tib, radixsort(FillDec(b, bsize), bsize), radixsort(FillRand(b, bsize), bsize), radixsort(FillInc(b, bsize), bsize));
    printRow(csize, tdc, trc, tic, radixsort(FillDec(c, csize), csize), radixsort(FillRand(c, csize), csize), radixsort(FillInc(c, csize), csize));
    printRow(dsize, tdd, trd, tid, radixsort(FillDec(d, dsize), dsize), radixsort(FillRand(d, dsize), dsize), radixsort(FillInc(d, dsize), dsize));
    printRow(esize, tde, tre, tie, radixsort(FillDec(e, esize), esize), radixsort(FillRand(e, esize), esize), radixsort(FillInc(e, esize), esize));
    
    //std::cout << radixsort(FillDec(a, asize), asize);

    std::cout << std::endl;
}
