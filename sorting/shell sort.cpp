#include<bits/stdc++.h>
using namespace std;
int shellSort(int arr[], int n)
{
    // Start with a gap and then reduce it
    for (int gap = n/2; gap > 0; gap /= 2)
    {
        // Do a gapped insertion sort for this gap size.
        // The first gap elements are already in gapped order
        // keep adding 1 more element until the entire array is gap sorted
        for (int i = gap; i < n; i += 1)
        {
            // add arr[i] to the elements that have been gap sorted
            // store arr[i] in temp and make a gap at position i
            int temp = arr[i];
  
            // shift earlier gap-sorted elements up until the correct location for a[i] is found
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
              
            //  put temp (the original a[i]) to its correct location
            arr[j] = temp;
        }
    }
    return 0;
}
  
void printArray(int arr[], int n)
{
    for (int i=0; i<n; i++)
        cout << arr[i] << " ";
}
  
int main()
{
    int arr[] = {10,4,5,12,2,1}, i;
    int n = sizeof(arr)/sizeof(arr[0]);
  
    cout << "Array before sorting: \n";
    printArray(arr, n);
  
    shellSort(arr, n);
  
    cout << "\nArray after sorting: \n";
    printArray(arr, n);
  
    return 0;
}