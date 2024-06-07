#include <iostream>
#include <string>
void heapify(std::string arr, int l, int r)
{
    //int l = L+1;
    char x = arr[l]; int i = l;
    while(true)
    {
        int j = 2*i;
        if(j>r) break;
        if(j<r && arr[j+1]<=arr[j]) j++;
        if(x<=arr[j]) break;
        arr[i]=arr[j];
        i=j;
    }
    arr[i]=x;
}

int main()
{
    std::string arr = "ytrewq";
    int l = 0, r = 5;
    heapify(arr, l, r);
    for(char i : arr)
        std::cout << i << " ";
    return 0;
}