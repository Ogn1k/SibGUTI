#include "fill_array.hpp"

// int bubbleSort(int arr[], int n)
// {
//     int move = 0, comp = 0;
//    int i, j;
//    for (i = 0; i < n-1; i++)
//        for (j = 0; j < n-i-1; j++) 
//        {
//             comp++;
//             if (arr[j] > arr[j+1])
//             {
                
//                 swap(&arr[j], &arr[j+1]);
//                 move++;
//             }
//        }
//     return comp+move;
               
// }

size_t bubbleSort1(int *arr, size_t n)
{
   size_t m = 0, c = 0;
   for(size_t i = 0; i<n; i++)
   {
    for(size_t j = 1; j<n - i; j++)
    {
        if(arr[j]<arr[j-1])
        {
            swap(arr[j], arr[j-1]);
            m+=3;
        }
        c++;
    }
   }
    return m+c;
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

    printTableHeader("bubble");
    printRow(asize, tda, tra, tia, bubbleSort1(FillDec(a, asize), asize), bubbleSort1(FillRand(a, asize), asize), bubbleSort1(FillInc(a, asize), asize));
    printRow(bsize, tdb, trb, tib, bubbleSort1(FillDec(b, bsize), bsize), bubbleSort1(FillRand(b, bsize), bsize), bubbleSort1(FillInc(b, bsize), bsize));
    printRow(csize, tdc, trc, tic, bubbleSort1(FillDec(c, 300), 300), bubbleSort1(FillRand(c, csize), csize), bubbleSort1(FillInc(c, csize), csize));
    printRow(dsize, tdd, trd, tid, bubbleSort1(FillDec(d, 400), 400), bubbleSort1(FillRand(d, dsize), dsize),  bubbleSort1(FillInc(d, dsize), dsize));
    printRow(esize, tde, tre, tie, bubbleSort1(FillDec(e, 500), 500), bubbleSort1(FillRand(e, esize), esize), bubbleSort1(FillInc(e, esize), esize));
	//std::cout << "| array size|         Theoretical M + C        |           M + C bubble           |"<< "\n";
	//std::cout << "|           | decreasing | random | increasing | decreasing | random | increasing |" << "\n";
	//std::cout << "|-----------+------------+--------+------------+------------+--------+------------|" << "\n";
	//std::cout << "|\t" << asize << " |\t\t" << tda << "|\t" << tra << "|\t\t" << tia << " |\t" << bubbleSort(FillDec(a, asize), asize) << "\t|" << bubbleSort(FillRand(a, asize), asize) << "\t|" << bubbleSort(FillInc(a, 100), 100) << "\t|" << "\n";
	// std::cout << "|\t" << bsize << " |\t\t" << tdb << "|\t" << trb << "|\t\t" << tib << " |\t" << bubbleSort(FillDec(b, 200), 200) << "\t|" << bubbleSort(FillRand(b, bsize), bsize) << "\t|" << bubbleSort(FillInc(b, bsize), bsize) << "\t|" << "\n";
	// std::cout << "|\t" << csize << " |\t\t" << tdc << "|\t" << trc << "|\t\t" << tic << " |\t" << bubbleSort(FillDec(c, 300), 300) << "\t|" <<  bubbleSort(FillRand(c, csize), csize) << "\t|" << bubbleSort(FillInc(c, csize), csize) << "\t|" << "\n";
	// std::cout << "|\t" << dsize << " |\t\t" << tdd << "|\t" << trd << "|\t\t" << tid << " |\t" << bubbleSort(FillDec(d, 400), 400) << "\t|" <<  bubbleSort(FillRand(d, dsize), dsize) << "\t|" << bubbleSort(FillInc(d, dsize), dsize) << "\t|" << "\n";
	// std::cout << "|\t" << esize << " |\t\t" << tde << "|\t" << tre << "|\t\t" << tie << " |\t" << bubbleSort(FillDec(e, 500), 500) << "\t|" << bubbleSort(FillRand(e, esize), esize) << "\t|" << bubbleSort(FillInc(e, esize), esize) << "\t|" << "\n";
	
    return 0;
}