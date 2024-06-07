#include <iostream>
#include "fill_array.hpp"

void QSort(int *arr, int size)
{
    int i=0, j=size-1;
    int mid=arr[size/2];

    do
    {
        while(arr[i]>mid)
            i++;

        while(arr[j]<mid)
            j--;

        if(i<=j)
        {
            int tmp=arr[i];
            arr[i]=arr[j];
            arr[j]=tmp;

            i++;
            j--;
        }
    } while (i<=j);

    if(j>0)
        QSort(arr,j+1);

    if(i<size)
        QSort(&arr[i], size-i);
}

int binsearch1(int* arr, int n, int x)
{
    int c=0;
    int l=1; int r=n; bool flag=false;
    int mid=0;
    while(l <= r)
    {
        c++;
        mid = (l+r)/2;
        if(arr[mid]==x) flag=true;
        c++;
        if(arr[mid]<x) l=mid+1;
        else r=mid-1;
    }
    return c;

}

int binsearch2(int* arr, int n, int x)
{
    int c=0;
    int l=1, r=n, mid=0;
    bool flag = false;
    while(l<r)
    {
        c++;
        mid=(l+r)/2;
        if(arr[mid]<x) l=mid+1;
        else r=mid;
    }
    c++;
    if(arr[r]==x) flag=true;
    else flag = false;
    return c;
}

int main()
{  
    const int asize=100, bsize=200,csize=500,dsize=1000;
    int aarr[asize], barr[bsize], carr[csize], darr[dsize];

    

    std::cout << "size: " << asize << " C1: " << binsearch1(FillInc(aarr, asize), asize, asize/2) << " C2: " << binsearch2(FillInc(aarr, asize), asize, asize/2) << std::endl;
    std::cout << "size: " << bsize << " C1: " << binsearch1(FillInc(barr, bsize), bsize, bsize/2) << " C2: " << binsearch2(FillInc(barr, bsize), bsize, bsize/2) << std::endl;
    std::cout << "size: " << csize << " C1: " << binsearch1(FillInc(carr, csize), csize, csize/2) << " C2: " << binsearch2(FillInc(carr, csize), csize, csize/2) << std::endl;
    std::cout << "size: " << dsize << " C1: " << binsearch1(FillInc(darr, dsize), dsize, dsize/2) << " C2: " << binsearch2(FillInc(darr, dsize), dsize, dsize/2) << std::endl;
    
    return 0;
}