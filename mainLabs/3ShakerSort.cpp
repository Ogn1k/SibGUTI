#include <array>
#include "fill_array.hpp"
#include <ctime>

// int shakerSort(int arr[], int n) 
// {
// 	int move = 0, comp = 0;

// 	int control = static_cast<int>(n - 1);
// 	int left = 0, right = control;
// 	do {
// 		for (int i = left; i < right; i++) 
// 		{
// 			comp++;
// 			if (arr[i] > arr[i + 1]) 
// 			{
				
// 				std::swap(arr[i], arr[i + 1]);
// 				control = i;
// 				move++;
// 			}
// 		}
// 		right = control;
// 		for (int i = right; i > left; i--) 
// 		{
// 			comp++;
// 			if (arr[i] < arr[i - 1]) {
				
// 				std::swap(arr[i], arr[i - 1]);
// 				control = i;
// 				move++;
// 			}
// 		}
// 		left = control;
// 	} while (left < right);
// 	return move+comp;
// }

size_t shakerSort(int *A, size_t len) {
    size_t L = 0, R = len - 1, k = len - 1;
    size_t m = 0, c = 0;
    do {
        for (size_t j = R; j > L; j--) {
            if (A[j] < A[j - 1]) {
                swap(A[j], A[j - 1]);
                m += 3;
                k = j;
            }
            c++;
        }
        L = k;
        for (size_t j = L; j < R; j++) {
            if (A[j] > A[j + 1]) {
                swap(A[j], A[j + 1]);
                m += 3;
                k = j;
            }
            c++;
        }
        R = k;
    } while (L < R);
    return m + c;
}

int main() 
{
	int asize=100,bsize=200,csize=300,dsize=400,esize=500;

	int tra=7425+4950, tia=0+99, tda=14850+4950;
    int trb=29850+19900, tib=0+199, tdb=59700+19900;
    int trc=67275+44850, tic=0+299, tdc=134550+44850;
    int trd=119700+79800, tid=0+399, tdd=239400+79800;
    int tre=187125+124750, tie=0+499, tde=374250+124750;

	int a[100];
	int b[200];
	int c[300];
	int d[400];
	int e[500]; 

	printTableHeader();
    printRow(asize, tda, tra, tia, shakerSort(FillDec(a, asize), asize), shakerSort(FillRand(a, asize), asize), shakerSort(FillInc(a, asize), asize));
    printRow(bsize, tdb, trb, tib, shakerSort(FillDec(b, bsize), bsize), shakerSort(FillRand(b, bsize), bsize), shakerSort(FillInc(b, bsize), bsize));
    printRow(csize, tdc, trc, tic, shakerSort(FillDec(c, 300), 300), shakerSort(FillRand(c, csize), csize), shakerSort(FillInc(c, csize), csize));
    printRow(dsize, tdd, trd, tid, shakerSort(FillDec(d, 400), 400), shakerSort(FillRand(d, dsize), dsize),  shakerSort(FillInc(d, dsize), dsize));
    printRow(esize, tde, tre, tie, shakerSort(FillDec(e, 500), 500), shakerSort(FillRand(e, esize), esize), shakerSort(FillInc(e, esize), esize));

	// std::cout << "| array size|           M + C insert           |"<< "\n";
	// std::cout << "|           | decreasing | random | increasing |" << "\n";
	// std::cout << "|-----------+----------------------------------|" << "\n";
	// std::cout << "|\t" << asize << " |\t" << shakerSort(FillDec(a, asize), asize) << "\t|" << shakerSort(FillRand(a, asize), asize) << "\t|" << shakerSort(FillInc(a, 100), 100) << "\t|" << "\n";
	// std::cout << "|\t" << bsize << " |\t" << shakerSort(FillDec(b, 200), 200) << "\t|" << shakerSort(FillRand(b, bsize), bsize) << "\t|" << shakerSort(FillInc(b, bsize), bsize) << "\t|" << "\n";
	// std::cout << "|\t" << csize << " |\t" << shakerSort(FillDec(c, 300), 300) << "\t|" <<  shakerSort(FillRand(c, csize), csize) << "\t|" << shakerSort(FillInc(c, csize), csize) << "\t|" << "\n";
	// std::cout << "|\t" << dsize << " |\t" << shakerSort(FillDec(d, 400), 400) << "\t|" <<  shakerSort(FillRand(d, dsize), dsize) << "\t|" << shakerSort(FillInc(d, dsize), dsize) << "\t|" << "\n";
	// std::cout << "|\t" << esize << " |\t" << shakerSort(FillDec(e, 500), 500) << "\t|" << shakerSort(FillRand(e, esize), esize) << "\t|" << shakerSort(FillInc(e, esize), esize) << "\t|" << "\n";
	

	return 0;
}