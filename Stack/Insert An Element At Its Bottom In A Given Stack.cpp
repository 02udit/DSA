#include <bits/stdc++.h>

// Function to create a new stack with an element pushed at the bottom
void newStack(stack<int>& s, int x) {
    // Base case: If the stack is empty, push the element and return
    if (s.empty()) {
        s.push(x);
        return;
    }

    // Recursive case:
    int num = s.top();  // Get the top element of the stack
    s.pop();            // Pop the top element
    newStack(s, x);     // Recursively call newStack to push the element at the bottom
    s.push(num);        // Push the element back after recursion
}

// Function to push an element at the bottom of the stack
stack<int> pushAtBottom(stack<int>& myStack, int x) {
    newStack(myStack, x);  // Call newStack to push the element at the bottom
    return myStack;        // Return the modified stack
}
