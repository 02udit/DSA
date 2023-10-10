#include <stack>
#include <vector>

// Function to find the next smaller element for each element in the array
vector<int> nextSmallerElement(vector<int> &arr, int n) {
    stack<int> s;          // Create a stack to store indices of elements in the array
    s.push(-1);            // Push a dummy index -1 onto the stack
    vector<int> ans(n);     // Create a vector to store the result

    // Iterate through the array in reverse order
    for(int i = n - 1; i >= 0; i--) {
        int curr = arr[i];  // Current element in the array

        // Pop elements from the stack until finding an element smaller than the current element
        while (s.top() >= curr) {
            s.pop();
        }

        ans[i] = s.top();   // Store the next smaller element in the result vector
        s.push(curr);       // Push the current element onto the stack
    }

    return ans;  // Return the vector containing the next smaller elements for each array element
}
