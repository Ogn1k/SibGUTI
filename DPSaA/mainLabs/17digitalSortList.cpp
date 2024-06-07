#include <cmath>
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "fill_array.hpp"

int getDigit(int number, int digitPlace) {
    return (number / static_cast<int>(pow(10, digitPlace))) % 10;
}

int radixSort(std::list<int>& lst) {
    int maxVal = *std::max_element(lst.begin(), lst.end());
    int digitPlace = 0;
    double swaps = 0;

    while (static_cast<int>(pow(10, digitPlace)) <= maxVal) {
        std::vector<std::list<int>> buckets(10);
        for (auto& num : lst) {
            int digitVal = getDigit(num, digitPlace);
            buckets[digitVal].push_back(num);
        }

        lst.clear();
        for (auto& bucket : buckets) {
            for (auto& num : bucket) {
                lst.push_back(num);
                swaps += (double)1/3;
            }
        }
        digitPlace++;
    }

    return round(swaps);
}

int main() {

    int asize=100,bsize=200,csize=300,dsize=400,esize=500;

    int tra=asize, tia=tra, tda=tra;
    int trb=bsize, tib=trb, tdb=trb;
    int trc=csize, tic=trc, tdc=trc;
    int trd=dsize, tid=trd, tdd=trd;
    int tre=esize, tie=tre, tde=tre;

    std::list<int> a(100);
    std::list<int> b(200);
    std::list<int> c(300);
    std::list<int> d(400);
    std::list<int> e(500); 

    printTableHeader("radixSort");
    printRow(asize, tda, tra, tia, radixSort(FillDecL(a, asize)), radixSort(FillRandL(a, asize)), radixSort(FillIncL(a, asize)));
    printRow(bsize, tdb, trb, tib, radixSort(FillDecL(b, bsize)), radixSort(FillRandL(b, bsize)), radixSort(FillIncL(b, bsize)));
    printRow(csize, tdc, trc, tic, radixSort(FillDecL(c, csize)), radixSort(FillRandL(c, csize)), radixSort(FillIncL(c, csize)));
    printRow(dsize, tdd, trd, tid, radixSort(FillDecL(d, dsize)), radixSort(FillRandL(d, dsize)), radixSort(FillIncL(d, dsize)));
    printRow(esize, tde, tre, tie, radixSort(FillDecL(e, esize)), radixSort(FillRandL(e, esize)), radixSort(FillIncL(e, esize)));
    

    std::cout << std::endl;

    return 0;
}
