#include <bits/stdc++.h>
using namespace std;

// Merge function to merge two sorted subarrays into one sorted array
void merge(int arr[], int s, int e, int &count)
{
    int mid = s + (e - s) / 2;

    int len1 = mid - s + 1; // Length of the first subarray
    int len2 = e - mid;     // Length of the second subarray

    // Create temporary arrays to hold the two subarrays
    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int actualArrayIndex = s;

    // Copy elements from the original array to the first subarray
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[actualArrayIndex++];
    }

    actualArrayIndex = mid + 1;

    // Copy elements from the original array to the second subarray
    for (int i = 0; i < len2; i++)
    {
        arr2[i] = arr[actualArrayIndex++];
    }

    int i = 0;
    int j = 0;
    actualArrayIndex = s;

    if (arr1[len1 - 1] <= arr2[0])
        return; // Skip the merge step if no merging is needed

    // Merge the two subarrays back into the original array
    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[actualArrayIndex++] = arr1[i++];
        }
        else
        {
            // If an element from the right subarray is smaller than an element from the left subarray, it means that
            // the element from the right subarray is smaller than all remaining elements
            // in the left subarray. So, we increment the 'count' variable
            // by the number of elements remaining in the left subarray (len1 - i).
            
            count += len1 - i; //-->>>inversion counter

            arr[actualArrayIndex++] = arr2[j++];
        }
    }

    // Copy any remaining elements from the first subarray
    while (i < len1)
    {
        arr[actualArrayIndex++] = arr1[i++];
    }

    // Copy any remaining elements from the second subarray
    while (j < len2)
    {
        arr[actualArrayIndex++] = arr2[j++];
    }

    // Free the dynamically allocated memory
    delete[] arr1;
    delete[] arr2;
}

// Merge Sort function that recursively divides and sorts the array
void sort(int arr[], int s, int e, int &count)
{
    // Base case: If the start index is greater than or equal to the end index, return.
    if (s >= e)
    {
        return;
    }

    // Calculate the middle index
    int mid = s + (e - s) / 2;

    // Recursively sort the first half of the array
    sort(arr, s, mid, count);

    // Recursively sort the second half of the array
    sort(arr, mid + 1, e, count);

    // Merge the two sorted halves
    merge(arr, s, e, count);
}

int main()
{
    int arr[9] = {5, 1, 3, 10, 13, 17, 15, 6, 11};

    cout << "Before sorting:" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int count = 0; //----->>>to calculate inversion count problem

    // Call the sort function to perform merge sort on the array
    sort(arr, 0, 8, count);

    cout << "After sorting:" << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Number of inversion count are = " << count << endl;
    return 0;
}
