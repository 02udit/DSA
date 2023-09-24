class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();    // Get the number of rows in the matrix
        int col = matrix[0].size(); // Get the number of columns in the matrix
        
        int rowIndex = 0;           // Initialize the row index to start from the first row
        int colIndex = col - 1;     // Initialize the column index to start from the last column
        
        // Use a while loop to traverse the matrix from top right to bottom left
        while (rowIndex < row && colIndex >= 0) {
            int element = matrix[rowIndex][colIndex];  // Get the element at the current position
            
            if (element == target) {
                return true;  // If the element is equal to the target, return true (found)
            } else if (element > target) {
                colIndex--;   // If the element is greater than the target, move left in the same row
            } else {
                rowIndex++;   // If the element is less than the target, move down to the next row
            }
        }
        
        return false;  // If the target element is not found, return false
    }
};
