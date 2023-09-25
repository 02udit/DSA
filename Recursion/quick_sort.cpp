#include<bits/stdc++.h>
using namespace std;

// Partition function to choose a pivot and rearrange elements such that elements smaller than pivot are on the left, and elements greater than pivot are on the right.
int partition(int arr[], int s, int e) {
    // Choose the first element (arr[s]) as the pivot.
    int pivot = arr[s];
    int count = 0;

    // Count the number of elements smaller than or equal to the pivot.
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    // Calculate the index where the pivot will be placed.
    int pivotIndex = s + count;

    // Swap the pivot element with its correct position in the sorted array.
    swap(arr[s], arr[pivotIndex]);

    int i = s;
    int j = e;

    // Rearrange elements such that elements smaller than or equal to the pivot are on the left, and elements greater than the pivot are on the right.
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            // Swap elements to place them in their correct partitions.
            swap(arr[i++], arr[j--]);
        }
    }

    // Return the index of the pivot element.
    return pivotIndex;
}

// Recursive Quick Sort function to sort the array.
void sort(int arr[], int s, int e) {
    // Base case: If the start index is greater than or equal to the end index, return.
    if (s >= e) {
        return;
    }

    // Partition the array and get the pivot index.
    int p = partition(arr, s, e);

    // Recursively sort the left and right subarrays.
    sort(arr, s, p - 1);
    sort(arr, p + 1, e);
}

int main() {
    int arr[9] = {5, 1, 3, 10, 13, 13, 15, 6, 11};

    cout << "Before sorting:" << endl;
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the sort function to perform Quick Sort on the entire array.
    sort(arr, 0, 8);

    cout << "After sorting:" << endl;
    for (int i = 0; i < 9; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
