#include<bits/stdc++.h>
using namespace std;

// Function to perform binary search for a target key in a sorted integer array
bool binarySearch(int arr[], int start, int end, int key) {
    // Base case: If the search range is empty (start > end), the key is not found.
    if (start > end) {
        return false;
    }

    // Calculate the middle index of the current search range.
    int mid = start + (end - start) / 2;

    // Check if the middle element of the array is equal to the target key.
    if (arr[mid] == key) {
        return true; // Return true if the key is found.
    } else if (arr[mid] < key) {
        // If the middle element is less than the key, perform binary search on the right half.
        return binarySearch(arr, mid + 1, end, key);
    } else {
        // If the middle element is greater than the key, perform binary search on the left half.
        return binarySearch(arr, start, mid - 1, key);
    }
}

int main() {
    int arr[9] = {3, 4, 6, 8, 9, 13, 17, 19, 21};
    int target = 17;
    int start = 0;
    int end = 8;

    // Call the binarySearch function to search for the target in the sorted array.
    if (binarySearch(arr, start, end, target)) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}
