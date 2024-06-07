template <typename T> void swap(T &var1, T &var2)
{
    auto temp = var1;
    var1 = var2;
    var2 = temp;
}

int bubbleSort(int arr[], int n)
{
    int move = 0, comp = 0;
   int i, j;
   for (i = 0; i < n; i++)
       for (j = 0; j < n-i; j++) 
       {
            //comp++;
            if (arr[j] > arr[j-1])
            {
                
                swap(&arr[j], &arr[j-1]);
                //move+=3;
            }
       }
    return comp+move;         
}