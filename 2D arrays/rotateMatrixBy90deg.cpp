class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int row = matrix.size();     // Get the number of rows in the matrix
         int col = matrix[0].size();  // Get the number of columns in the matrix
         int currentRow = 0;          // Initialize the currentRow variable to 0
         int currentCol = 0;          // Initialize the currentCol variable to 0
         
         // Iterate through the upper-left quadrant of the matrix
         for (int i = currentRow; i < row; i++) {
             for (int j = currentCol; j < col; j++) {
                 if (i == j) continue;  // Skip the diagonal elements
                 else {
                     int temp = matrix[i][j];     // Store the current element in a temporary variable
                     matrix[i][j] = matrix[j][i];  // Swap the current element with its transposed element
                     matrix[j][i] = temp;          // Assign the stored value to the transposed element
                 }
             }
             
             int m = 0;           // Initialize the m variable to 0
             int n = col - 1;     // Initialize the n variable to the last column index
             
             // Swap elements in the current row to rotate it 90 degrees clockwise
             while (m < n) {
                 swap(matrix[i][m++], matrix[i][n--]);  // Swap the elements at positions m and n
             }
             
             currentRow++;   // Move to the next row
             currentCol++;   // Move to the next column
         }
    }
};




//using pre defined functions ---------->>>>


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size();    // Get the number of rows in the matrix
        int col = matrix[0].size(); // Get the number of columns in the matrix

        // Iterate through the upper triangular portion of the matrix
        for (int i = 0; i < row; i++) {
            for (int j = i; j < col; j++) {
                swap(matrix[i][j], matrix[j][i]); // Swap the elements at (i, j) and (j, i) to perform transpose
            }
            
            // Reverse the current row to complete the 90-degree clockwise rotation
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

