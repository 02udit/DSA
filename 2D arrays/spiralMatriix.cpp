class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;        // Initialize a vector to store the spiral order elements
        int row = matrix.size(); // Get the number of rows in the matrix
        int col = matrix[0].size(); // Get the number of columns in the matrix

        int totalElements = row * col; // Calculate the total number of elements in the matrix
        int count = 0; // Initialize a count variable to keep track of the number of elements added to ans
        int startRow = 0; // Initialize the starting row index
        int startCol = 0; // Initialize the starting column index
        int endRow = row - 1; // Initialize the ending row index
        int endCol = col - 1; // Initialize the ending column index
        
        // Use a while loop to traverse the matrix in a spiral order
        while (count < totalElements) {
            // Traverse from left to right along the top row
            for (int i = startCol; i <= endCol && count < totalElements; i++) {
                ans.push_back(matrix[startRow][i]);
                count++;
            }
            startRow++; // Move to the next row
            
            // Traverse from top to bottom along the rightmost column
            for (int i = startRow; i <= endRow && count < totalElements; i++) {
                ans.push_back(matrix[i][endCol]);
                count++;
            }
            endCol--; // Move to the previous column
            
            // Traverse from right to left along the bottom row
            for (int i = endCol; i >= startCol && count < totalElements; i--) {
                ans.push_back(matrix[endRow][i]);
                count++;
            }
            endRow--; // Move to the previous row
            
            // Traverse from bottom to top along the leftmost column
            for (int i = endRow; i >= startRow && count < totalElements; i--) {
                ans.push_back(matrix[i][startCol]);
                count++;
            }
            startCol++; // Move to the next column
        }
        
        return ans; // Return the vector containing the spiral order elements
    }
};
