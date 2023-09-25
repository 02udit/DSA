#include<bits/stdc++.h>
using namespace std;

// Function to check if a key is found in an integer array using recursion
bool isFound(int arr[], int size, int key) {
    // Base case:
    // If the array is empty (size == 0), the key is not found.
    if (size == 0) {
        return false;
    }
    
    // Check if the first element of the array is equal to the key.
    if (arr[0] == key) {
        return true; // Return true if the key is found.
    } else {
        // If the first element is not equal to the key,
        // make a recursive call to isFound on the rest of the array (arr + 1) with size reduced by 1 (size - 1).
        return isFound(arr + 1, size - 1, key);
    }
}

int main() {
    int arr[5] = {3, 9, 1, 8, 15};
    int key = 7;

    // Call the isFound function to check if the key is found in the array.
    if (isFound(arr, 5, key)) {
        cout << "Element found." << endl;
    } else {
        cout << "Element not found." << endl;
    }

    return 0;
}
