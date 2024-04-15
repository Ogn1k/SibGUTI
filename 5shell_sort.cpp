#include <vector>
#include <cmath>
#include "fill_array.hpp"
 
// int shellSort(int arr[], int n) 
// { 
//     int move = 0, comp = 0;
//     for (int gap = n/2; gap > 0; gap /= 2) 
//     {  
//         for (int i = gap; i < n; i += 1) 
//         { 
//             int temp = arr[i]; 
  
//             int j;             
//             for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
//             {
//                 arr[j] = arr[j - gap]; 
//                 move+=1;
//             }
//             arr[j] = temp; 
//         } 
//     } 
//     return move; 
// } 
  
size_t shellSort(int *A, size_t len) 
{
    size_t m = 0, c = 0;
    size_t M = (int)std::log2(len) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1;
    for (int a = M - 1; a >= 0; a--) {
        for (size_t i = h[a]; i < len; i++) {
            bool f = true;
            for (int j = i - h[a]; j >= 0 && A[j] > A[j + h[a]]; j -= h[a]) {
                swap(A[j], A[j + h[a]]);
                m += 3;
                f = false;
                c++;
            }
            if (f)
                c++;
        }
    }
    return m + c;
}
  
int main() 
{ 

    int asize=100,bsize=200,csize=300,dsize=400,esize=500;

    int tra=0, tia=0, tda=0;
    int trb=0, tib=0, tdb=0;
    int trc=0, tic=0, tdc=0;
    int trd=0, tid=0, tdd=0;
    int tre=0, tie=0, tde=0;

    int a[100];
    int b[200];
    int c[300];
    int d[400];
    int e[500]; 

    printTableHeader("shellsort");
    printRow(asize, tda, tra, tia, shellSort(FillDec(a, asize), asize), shellSort(FillRand(a, asize), asize), shellSort(FillInc(a, asize), asize));
    printRow(bsize, tdb, trb, tib, shellSort(FillDec(b, bsize), bsize), shellSort(FillRand(b, bsize), bsize), shellSort(FillInc(b, bsize), bsize));
    printRow(csize, tdc, trc, tic, shellSort(FillDec(c, 300), 300), shellSort(FillRand(c, csize), csize), shellSort(FillInc(c, csize), csize));
    printRow(dsize, tdd, trd, tid, shellSort(FillDec(d, 400), 400), shellSort(FillRand(d, dsize), dsize),  shellSort(FillInc(d, dsize), dsize));
    printRow(esize, tde, tre, tie, shellSort(FillDec(e, 500), 500), shellSort(FillRand(e, esize), esize), shellSort(FillInc(e, esize), esize));
    
    return 0; 
}   

