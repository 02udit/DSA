class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();    // Get the number of rows in the matrix
        int col = matrix[0].size(); // Get the number of columns in the matrix
        
        int start = 0;              // Initialize the start pointer
        int end = row * col - 1;    // Initialize the end pointer, representing the last index
        int mid;                    // Initialize the mid variable to store the middle index
        
        // Use binary search to find the target element
        while (start <= end) {
            mid = start + (end - start) / 2;  // Calculate the middle index
            
            int element = matrix[mid / col][mid % col];  // Get the element at the middle index
            
            if (element == target) {
                return true;  // If the element is equal to the target, return true (found)
            } else if (element > target) {
                end = mid - 1;  // If the element is greater than the target, search in the left half
            } else {
                start = mid + 1;  // If the element is less than the target, search in the right half
            }
        }
        
        return false;  // If the target element is not found, return false
    }
};
