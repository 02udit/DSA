#include <bits/stdc++.h> 

// Function to find and remove the middle element of a stack
void middle(stack<int>& s, int N, int count) {
    // Base case: If the count reaches the middle of the stack
    if (count == N / 2) {
        s.pop(); // Remove the middle element
        return;
    }

    // Recursive case:
    int num = s.top(); // Get the top element of the stack
    s.pop();           // Pop the top element
    middle(s, N, count + 1); // Recursively process the remaining elements
    s.push(num);       // Push the element back after recursion
}

// Function to delete the middle element from a given stack
void deleteMiddle(stack<int>& inputStack, int N) {
    int count = 0; // Initialize the count of processed elements to 0
    middle(inputStack, N, count); // Call the recursive middle function to remove the middle element
}

