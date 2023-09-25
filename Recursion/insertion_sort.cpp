#include<bits/stdc++.h>
using namespace std;

// Function to perform insertion sort recursively
void sort(int arr[], int size, int i) {
    // Base case:
    // If the index 'i' exceeds the size of the array, return.
    if (i >= size) {
        return;
    }

    // Store the current element to be inserted at the right position.
    int temp = arr[i];

    // Initialize 'j' to the previous index.
    int j;

    // Iterate backwards to find the correct position for 'temp' in the sorted part of the array.
    for (j = i - 1; j >= 0; j--) {
        if (arr[j] > temp) {
            arr[j + 1] = arr[j]; // Shift elements to the right to make space for 'temp'.
        } else {
            break; // Break the loop when 'temp' is in its correct position.
        }
    }

    // Insert 'temp' at the correct position.
    arr[j + 1] = temp;

    // Recursively call the sort function to insert the next element in the array.
    sort(arr, size, i + 1);
}

int main() {
    int arr[7] = {5, 1, 3, 10, 13, 17, 15};

    cout << "Before sorting:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Call the sort function to perform insertion sort on the array.
    sort(arr, 7, 1);

    cout << "After sorting:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
