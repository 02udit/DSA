#include <bits/stdc++.h> 

// Function to insert an element at the correct position in a sorted stack
void sortedInsert(stack<int> &s, int num) {
    // Base case: If the stack is empty or the top element is smaller than the new element
    if (s.empty() || s.top() < num) {
        s.push(num);  // Push the new element onto the stack
        return;
    }

    // Recursive case:
    int n = s.top();  // Get the top element of the stack
    s.pop();          // Pop the top element
    sortedInsert(s, num);  // Recursively call sortedInsert to insert the element at the correct position
    s.push(n);       // Push the element back after recursion
}

// Function to sort a stack using recursion
void sortStack(stack<int> &stack) {
    // Base case: If the stack is empty, return
    if (stack.empty()) {
        return;
    }

    // Recursive case:
    int num = stack.top();  // Get the top element of the stack
    stack.pop();            // Pop the top element
    sortStack(stack);       // Recursively call sortStack to sort the remaining elements
    sortedInsert(stack, num);  // Insert the current top element at the correct position in the sorted stack
}
