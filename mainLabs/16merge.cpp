#include <iostream>
#include "fill_array.hpp"
#include <math.h>
#include <list>

//std::pair<int, int> comparisons_and_swaps = {0, 0};

std::list<int> merge(std::list<int>& left, std::list<int>& right, int &swapCount, int &comparisonCount) {
    std::list<int> result;
    while (!left.empty() && !right.empty()) {
        comparisonCount++;
        if (left.front() <= right.front()) {
            result.push_back(left.front());
            left.pop_front();
        } else {
            result.push_back(right.front());
            right.pop_front();
            swapCount++;
        }
    }

    while (!left.empty()) {
        result.push_back(left.front());
        left.pop_front();
    }

    while (!right.empty()) {
        result.push_back(right.front());
        right.pop_front();
    }

    return result;
}

std::list<int> mergeSort(std::list<int>& lst, int &swapCount, int &comparisonCount) {
    if (lst.size() <= 1) {
        return lst;
    }

    std::list<int> left, right;
    std::list<int>::iterator middle = lst.begin();
    std::advance(middle, lst.size() / 2);
    left.splice(left.begin(), lst, lst.begin(), middle);
    right.splice(right.begin(), lst);

    left = mergeSort(left,swapCount,comparisonCount);
    right = mergeSort(right,swapCount,comparisonCount);
    return merge(left, right,swapCount,comparisonCount);
}


int mergeSortSC(std::list<int> &arr)
{
    int swapCount=0, comparisonCount=0;
    mergeSort(arr,swapCount,comparisonCount);
    return swapCount+comparisonCount;
}

int main() {

    int asize=100,bsize=200,csize=300,dsize=400,esize=500;
//664 5549 5549
    int tra=asize*log2(asize), tia=tra, tda=tra;
    int trb=bsize*log2(bsize), tib=trb, tdb=trb;
    int trc=csize*log2(csize), tic=trc, tdc=trc;
    int trd=dsize*log2(dsize), tid=trd, tdd=trd;
    int tre=esize*log2(esize), tie=tre, tde=tre;


    //mergeSortSC(arr, 0, n - 1, s, c);

    std::list<int> a(100);
    std::list<int> b(200);
    std::list<int> c(300);
    std::list<int> d(400);
    std::list<int> e(500); 

printTableHeader("mergeSortSC");
    printRow(asize, tda, tra, tia, mergeSortSC(FillDecL(a, asize)), mergeSortSC(FillRandL(a, asize)), mergeSortSC(FillIncL(a, asize)));
    printRow(bsize, tdb, trb, tib, mergeSortSC(FillDecL(b, bsize)), mergeSortSC(FillRandL(b, bsize)), mergeSortSC(FillIncL(b, bsize)));
    printRow(csize, tdc, trc, tic, mergeSortSC(FillDecL(c, 300)), mergeSortSC(FillRandL(c, csize)), mergeSortSC(FillIncL(c, csize)));
    printRow(dsize, tdd, trd, tid, mergeSortSC(FillDecL(d, 400)), mergeSortSC(FillRandL(d, dsize)),  mergeSortSC(FillIncL(d, dsize)));
    printRow(esize, tde, tre, tie, mergeSortSC(FillDecL(e, 500)), mergeSortSC(FillRandL(e, esize)), mergeSortSC(FillIncL(e, esize)));
    

    std::cout << std::endl;

    return 0;
}
