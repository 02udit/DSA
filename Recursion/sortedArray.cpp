#include<bits/stdc++.h>
using namespace std;

// Function to check if an array is sorted in non-decreasing order using recursion
bool isSorted(int arr[], int size) {
    // Base cases:
    // If the array is empty or has only one element, it's considered sorted.
    if (size == 0 || size == 1) {
        return 1; // Return 1 to indicate sorted.
    }

    // Compare the first two elements of the array.
    if (arr[0] > arr[1]) {
        return 0; // Return 0 to indicate not sorted.
    } else {
        // If the first two elements are in non-decreasing order,
        // recursively check the rest of the array (excluding the first element).
        return isSorted(arr + 1, size - 1);
    }
}

int main() {
    int arr[5] = {2, 4, 6, 7, 10};

    // Call the isSorted function to check if the array is sorted.
    if (isSorted(arr, 5)) {
        cout << "Array is sorted." << endl;
    } else {
        cout << "Array is not sorted." << endl;
    }

    return 0;
}
