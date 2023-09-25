#include<bits/stdc++.h>
using namespace std;

// Function to perform a single pass of bubble sort
void sort(int arr[], int size) {
    // Base cases:
    // If the array is empty (size == 0) or has only one element (size == 1),
    // it is already sorted, so return.
    if (size == 0 || size == 1) {
        return;
    }

    // Perform a single pass of bubble sort to move the largest element to the last position.
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            swap(arr[i], arr[i + 1]); // Swap adjacent elements if they are in the wrong order.
        }
    }

    // Recursively call the sort function on the remaining (unsorted) part of the array.
    sort(arr, size - 1);
}

int main() {
    int arr[7] = {5, 1, 3, 10, 13, 17, 15};

    cout << "Before sorting:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the sort function to perform bubble sort on the array.
    sort(arr, 7);

    cout << "After sorting:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
