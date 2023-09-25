#include<bits/stdc++.h>
using namespace std;

// Function to calculate the sum of elements in an integer array using recursion
int getSum(int arr[], int size) {
    // Base cases:
    // If the array is empty (size == 0), the sum is 0.
    if (size == 0) {
        return 0;
    }
    // If the array has only one element (size == 1), the sum is that element.
    else if (size == 1) {
        return arr[0];
    }

    // Recursive case:
    // Calculate the sum of the first element (arr[0]) and the sum of the rest of the array.
    // Recursively call getSum on the rest of the array (arr + 1) with size reduced by 1 (size - 1).
    return arr[0] + getSum(arr + 1, size - 1);
}

int main() {
    int arr[5] = {4, 10, 23, 6, 7};

    // Call the getSum function to calculate the sum of elements in the array.
    int sum = getSum(arr, 5);

    // Print the sum of elements in the array.
    cout << "Sum of elements of the array is = " << sum << endl;

    return 0;
}
