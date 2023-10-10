#include <bits/stdc++.h>

// Function to insert an element at the bottom of the stack
void insertAtBottom(stack<int> &s, int num) {
    // Base case: If the stack is empty, push the element and return
    if (s.empty()) {
        s.push(num);
        return;
    }

    // Recursive case:
    int n = s.top();  // Get the top element of the stack
    s.pop();          // Pop the top element
    insertAtBottom(s, num);  // Recursively call insertAtBottom to push the element at the bottom
    s.push(n);       // Push the element back after recursion
}

// Function to reverse the order of elements in a stack
void reverseStack(stack<int> &stack) {
    // Base case: If the stack is empty, return
    if (stack.empty()) {
        return;
    }

    // Recursive case:
    int num = stack.top();  // Get the top element of the stack
    stack.pop();            // Pop the top element
    reverseStack(stack);    // Recursively call reverseStack to reverse the remaining elements
    insertAtBottom(stack, num);  // Insert the current top element at the bottom of the reversed stack
}
