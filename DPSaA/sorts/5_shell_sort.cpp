#include <cmath>
#include <vector>

template <typename T> void swap(T &var1, T &var2)
{
    auto temp = var1;
    var1 = var2;
    var2 = temp;
}

int shellSort(int arr[], int n)
{
    // Start with a big gap, then reduce the gap
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements a[0..gap-1] are already in gapped order
        // keep adding one more element until the entire array is
        // gap sorted 
        for (int i = gap; i < n; i += 1)
        {
            // add a[i] to the elements that have been gap sorted
            // save a[i] in temp and make a hole at position i
            int temp = arr[i];
 
            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
             
            //  put temp (the original a[i]) in its correct location
            arr[j] = temp;
        }
    }
    return 0;
}

int shellSort2(int *A, int len) 
{
    int m = 0, c = 0;
    int M = (int)std::log2(len) - 1;
    std::vector<int> h(M);
    h[0] = 1;
    for (int i = 1; i < M; i++)
        h[i] = 2 * h[i - 1] + 1; // algo
    for (int a = M - 1; a >= 0; a--) {
        for (int i = h[a]; i < len; i++) {
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

