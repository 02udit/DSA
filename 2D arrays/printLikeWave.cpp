#include <bits/stdc++.h>  // Include standard C++ libraries

// Function to perform wave print on a 2D vector
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;  // Create a vector to store the wave printed elements

    // Loop through each column in the matrix
    for (int i = 0; i < mCols; i++) {
        if (i & 1) {  // If the column index is odd (i.e., starting from 1), move in reverse order
            for (int j = nRows - 1; j >= 0; j--) {
                ans.push_back(arr[j][i]);  // Add the element at the current position to the answer vector
            }
        } else {  // If the column index is even (i.e., starting from 0), move in normal order
            for (int j = 0; j < nRows; j++) {
                ans.push_back(arr[j][i]);  // Add the element at the current position to the answer vector
            }
        }
    }
    return ans;  // Return the vector containing the wave printed elements
}
