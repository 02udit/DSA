/*You are required to complete this method*/

#include <vector>
#include <stack>
#include <climits> // for INT_MIN
using namespace std;

class Solution {
private:
    // Function to find the previous smaller element index for each element in the array
    vector<int> prevSmaller(int* arr, int m) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(m);
        for (int i = 0; i < m; i++) {
            int curr = arr[i];
            // Pop elements from the stack until a smaller element is found
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top(); // Store the index of the previous smaller element
            s.push(i);
        }
        return ans;
    }

    // Function to find the next smaller element index for each element in the array
    vector<int> nextSmaller(int* arr, int m) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(m);
        for (int i = m - 1; i >= 0; i--) {
            int curr = arr[i];
            // Pop elements from the stack until a smaller element is found
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            ans[i] = s.top(); // Store the index of the next smaller element
            s.push(i);
        }
        return ans;
    }

    // Function to calculate the largest rectangle area in a histogram
    int largestRectArea(int* arr, int m) {
        // Find the indices of the previous smaller and next smaller elements for each element
        vector<int> nextSmall(m);
        nextSmall = nextSmaller(arr, m);
        vector<int> prevSmall(m);
        prevSmall = prevSmaller(arr, m);

        int area = INT_MIN;

        // Iterate through each element to calculate the maximum rectangle area
        for (int i = 0; i < m; i++) {
            int length = arr[i];
            
            // If next smaller index is not found, assume it is the size of the array
            if (nextSmall[i] == -1) {
                nextSmall[i] = m;
            }

            // Calculate the breadth of the rectangle
            int breadth = nextSmall[i] - prevSmall[i] - 1;

            // Calculate the area of the rectangle
            int newArea = length * breadth;

            // Update the maximum area if needed
            area = max(area, newArea);
        }

        return area;
    }

public:
    // Function to find the maximum area rectangle in a binary matrix
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Initialize the maximum area with the largest rectangle area in the first row
        int area = largestRectArea(M[0], m);

        // Iterate through each row starting from the second row
        for (int i = 1; i < n; i++) {
            // Update the values in each column based on the accumulation of non-zero values
            for (int j = 0; j < m; j++) {
                if (M[i][j] != 0)
                    M[i][j] = M[i][j] + M[i - 1][j];
                else
                    M[i][j] = 0;
            }

            // Update the maximum area if needed based on the largest rectangle area in the current row
            area = max(area, largestRectArea(M[i], m));
        }

        return area;
    }
};
