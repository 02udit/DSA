class Solution {
private:
    // Function to find the previous smaller element for each element in the array
    vector<int> previousSmaller(vector<int>& arr, int n) {
        vector<int> ans(n);  // Create a vector to store the result
        stack<int> s;        // Create a stack to store indices of elements in the array
        s.push(-1);          // Push a dummy index -1 onto the stack

        // Iterate through the array
        for(int i = 0; i < n; i++) {
            int curr = arr[i];  // Current element in the array

            // Pop elements from the stack until finding an element smaller than the current element
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();  // Store the previous smaller element in the result vector
            s.push(i);         // Push the current index onto the stack
        }
        return ans;
    }

    // Function to find the next smaller element for each element in the array
    vector<int> nextSmaller(vector<int>& arr, int n) {
        vector<int> ans(n);  // Create a vector to store the result
        stack<int> s;        // Create a stack to store indices of elements in the array
        s.push(-1);          // Push a dummy index -1 onto the stack

        // Iterate through the array in reverse order
        for(int i = n - 1; i >= 0; i--) {
            int curr = arr[i];  // Current element in the array

            // Pop elements from the stack until finding an element smaller than the current element
            while(s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }

            ans[i] = s.top();  // Store the next smaller element in the result vector
            s.push(i);         // Push the current index onto the stack
        }
        return ans;
    }

public:
    // Function to find the largest rectangle area in a histogram
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();  // Get the size of the input array

        // Find the previous smaller element for each element in the array
        vector<int> prev = previousSmaller(heights, n);

        // Find the next smaller element for each element in the array
        vector<int> next = nextSmaller(heights, n);

        int area = INT_MIN;  // Initialize the maximum area variable

        // Iterate through each element in the array
        for(int i = 0; i < n; i++) {
            int l = heights[i];  // Current height of the histogram bar

            // If there is no next smaller element, set it to the end of the array
            if (next[i] == -1) {
                next[i] = n;
            }

            int b = next[i] - prev[i] - 1;  // Width of the rectangle
            int newArea = l * b;  // Calculate the area of the rectangle

            area = max(area, newArea);  // Update the maximum area
        }

        return area;  // Return the maximum area of the histogram
    }
};
