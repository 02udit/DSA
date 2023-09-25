#include<bits/stdc++.h>
using namespace std;

// Function to perform selection sort recursively
void sort(int arr[], int size) {
    // Base cases:
    // If the array is empty (size == 0) or has only one element (size == 1),
    // it is already sorted, so return.
    if (size == 0 || size == 1) {
        return;
    }

    // Find the index of the minimum element in the current unsorted portion of the array.
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i;
        }
    }

    // Swap the minimum element with the first element to move it to the sorted portion.
    swap(arr[0], arr[minIndex]);

    // Recursively call the sort function on the remaining (unsorted) part of the array.
    sort(arr + 1, size - 1);
}

int main() {
    int arr[7] = {5, 1, 3, 10, 13, 17, 15};

    cout << "Before sorting:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the sort function to perform selection sort on the array.
    sort(arr, 7);

    cout << "After sorting:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
