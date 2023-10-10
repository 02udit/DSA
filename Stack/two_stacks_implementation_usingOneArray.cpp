#include <bits/stdc++.h> 

// Define a class named TwoStack
class TwoStack {

public:
    int top1;    // Top index of stack 1
    int top2;    // Top index of stack 2
    int *arr;    // Dynamic array to store the elements of both stacks
    int size;    // Maximum size of the array

    // Constructor to initialize the TwoStack with a given size
    TwoStack(int s) {
        top1 = -1;         // Initialize top1 to -1, indicating an empty stack 1
        top2 = s;          // Initialize top2 to the maximum size, indicating an empty stack 2
        arr = new int[s];   // Allocate memory for the dynamic array
        this->size = s;     // Set the size of the array
    }

    // Push operation for stack 1
    void push1(int num) {
        if (top2 - top1 > 1) {
            top1++;             // Increment top1
            arr[top1] = num;     // Add the element to stack 1
        }   
    }

    // Push operation for stack 2
    void push2(int num) {
        if (top2 - top1 > 1) {
            top2--;             // Decrement top2
            arr[top2] = num;     // Add the element to stack 2
        }
    }

    // Pop operation for stack 1
    int pop1() {
        if (top1 >= 0) {
            int ans = arr[top1]; // Retrieve the top element of stack 1
            top1--;              // Decrement top1 to remove the element
            return ans;          // Return the popped element
        } else {
            return -1;           // Return -1 if stack 1 is empty
        }
    }

    // Pop operation for stack 2
    int pop2() {
        if (top2 < size) {
            int ans = arr[top2]; // Retrieve the top element of stack 2
            top2++;              // Increment top2 to remove the element
            return ans;          // Return the popped element
        } else {
            return -1;           // Return -1 if stack 2 is empty
        }
    }
};
