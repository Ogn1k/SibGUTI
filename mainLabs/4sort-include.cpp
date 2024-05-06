#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <iostream>
#include "fill_array.hpp"

// int inclusionSort(int* num, int size)
// {
//   int comp=0;
//   int move=0;
//   for (int i = 1; i < size; i++)
//   {
//     int value = num[i]; 
//     int index = i;     
//     while ((index > 0) && (num[index - 1] > value))
//     {   
//       comp++;
//       num[index] = num[index - 1];
//       index--;
//     }
//     if(num[index-1]<=value)
//       comp++;
//     move++;
//     num[index] = value; 
//   }
//   return comp+move;
// }

size_t inclusionSort(int *A, size_t len) {
    size_t m = 0, c = 0;
    for (size_t i = 1; i < len; i++) {
        bool f = true;
        auto t = A[i];
        long long j = i - 1;
        while (j > -1 && t < A[j]) {
            f = false;
            A[j + 1] = A[j];
            j--;
            c++;
            m++;
        }
        if (f)
            c++;
        A[j + 1] = t;
        m += 2;
    }
    return m + c;
}

int main()
{
  int asize=100,bsize=200,csize=300,dsize=400,esize=500;

  int tra=2574+2475, tia=198+99, tda=5148+4950;
  int trb=10149+9950, tib=398+199, tdb=20298+19900;
  int trc=22724+22425, tic=598+299, tdc=45448+44850;
  int trd=40299+39900, tid=798+399, tdd=80598+79800;
  int tre=62874+62375, tie=998+499, tde=125748+124750;

  int a[100];
  int b[200];
  int c[300];
  int d[400];
  int e[500];
  
  printTableHeader("includesort");
  printRow(asize, tda, tra, tia, inclusionSort(FillDec(a, asize), asize), inclusionSort(FillRand(a, asize), asize), inclusionSort(FillInc(a, asize), asize));
  printRow(bsize, tdb, trb, tib, inclusionSort(FillDec(b, bsize), bsize), inclusionSort(FillRand(b, bsize), bsize), inclusionSort(FillInc(b, bsize), bsize));
  printRow(csize, tdc, trc, tic, inclusionSort(FillDec(c, 300), 300), inclusionSort(FillRand(c, csize), csize), inclusionSort(FillInc(c, csize), csize));
  printRow(dsize, tdd, trd, tid, inclusionSort(FillDec(d, 400), 400), inclusionSort(FillRand(d, dsize), dsize),  inclusionSort(FillInc(d, dsize), dsize));
  printRow(esize, tde, tre, tie, inclusionSort(FillDec(e, 500), 500), inclusionSort(FillRand(e, esize), esize), inclusionSort(FillInc(e, esize), esize));
  

  // std::cout << "| array size|           M + C insert           |"<< "\n";
  // std::cout << "|           | decreasing | random | increasing |" << "\n";
  // std::cout << "|-----------+" << "\n";
  // std::cout << "|\t" << asize << " |\t" << inclusionSort(FillDec(a, asize), asize) << "\t|" << inclusionSort(FillRand(a, asize), asize) << "\t|" << inclusionSort(FillInc(a, 100), 100) << "\t|" << "\n";
  // std::cout << "|\t" << bsize << " |\t" << inclusionSort(FillDec(b, 200), 200) << "\t|" << inclusionSort(FillRand(b, bsize), bsize) << "\t|" << inclusionSort(FillInc(b, bsize), bsize) << "\t|" << "\n";
  // std::cout << "|\t" << csize << " |\t" << inclusionSort(FillDec(c, 300), 300) << "\t|" <<  inclusionSort(FillRand(c, csize), csize) << "\t|" << inclusionSort(FillInc(c, csize), csize) << "\t|" << "\n";
  // std::cout << "|\t" << dsize << " |\t" << inclusionSort(FillDec(d, 400), 400) << "\t|" <<  inclusionSort(FillRand(d, dsize), dsize) << "\t|" << inclusionSort(FillInc(d, dsize), dsize) << "\t|" << "\n";
  // std::cout << "|\t" << esize << " |\t" << inclusionSort(FillDec(e, 500), 500) << "\t|" << inclusionSort(FillRand(e, esize), esize) << "\t|" << inclusionSort(FillInc(e, esize), esize) << "\t|" << "\n";
  return 0;
}           