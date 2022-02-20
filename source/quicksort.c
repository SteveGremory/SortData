#include "quicksort.h"

int partition(int array[], int low, int high)
{
    int i = (low - 1); // One element before low so that
                     // we can also take the actual first element
                     // into account
    int pivot = array[high]; // Start at the end of the array
    
    // Iterate backwards    
    for(int j = low; j <= high - 1; j++) 
    {
        // If the current element is smaller than the index
        if(array[j] < pivot) 
        {
            // Increment the index and swap the elements
            i++;
            SWAP(int, array[i], array[j]);        
        }
    }
    SWAP(int, array[i + 1], array[high]);
   
    return (i + 1);
}

void quicksort(int array[], int low, int high)
{
    if (low <= high)
    {
        int pivot = partition(array, low, high);
        quicksort(array, low, pivot -1);    // Before the pivot,
                                            // Smaller values.
        
        quicksort(array, pivot + 1, high);  // After the pivot,
                                            // Bigger values.        
    }
}
