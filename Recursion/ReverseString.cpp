#include <bits/stdc++.h> 
using namespace std;

// Function to reverse a string in-place using recursion
void revStr(string& str, int i, int j) {
    // Base case: If the left index (i) is greater than the right index (j),
    // the entire string has been reversed, so return.
    if (i > j) {
        return;
    }

    // Swap the characters at indices i and j in the string.
    swap(str[i], str[j]);

    // Move the left index (i) one step forward and the right index (j) one step backward.
    i++;
    j--;

    // Recursively call the revStr function with the updated indices.
    revStr(str, i, j);
}

// NOTE: we can also write (n-i-1) instead of j (where n is str length)

// Function to reverse a string using recursion
string reverseString(string str) {
    int i = 0;                // Left index of the string
    int j = str.length() - 1; // Right index of the string

    // Call the revStr function to reverse the string in-place.
    revStr(str, i, j);

    // Return the reversed string.
    return str;
}

int main() {
    // Input string
    string str = "Hello, World!";

    // Call the reverseString function to reverse the input string.
    string reversedStr = reverseString(str);

    // Print the reversed string.
    cout << "Reversed string: " << reversedStr << endl;

    return 0;
}


