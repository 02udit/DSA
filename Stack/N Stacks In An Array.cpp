#include <bits/stdc++.h> 

class NStack {
private:
    int* arr;     // Array to store the elements of all stacks
    int* top;     // Array to keep track of the top element of each stack
    int* next;    // Array to keep track of the next available spot in the array

    int freeSpot; // Index of the next available spot
    int n, s;     // n: Number of stacks, s: Size of the array

public:
    // Constructor to initialize the data structure
    NStack(int N, int S) {
        n = N;
        s = S;
        arr = new int[s];
        top = new int[n];
        next = new int[s];
        
        // Initialize top array with -1 indicating empty stacks
        for (int i = 0; i < n; i++) {
            top[i] = -1;
        } // or we can use memset(top,-1,n);

        // Initialize next array to link all spots in the array
        for (int i = 0; i < s; i++) {
            next[i] = i + 1;
        }
        next[s - 1] = -1; // Last spot points to -1 indicating end of array

        freeSpot = 0; // Start with the first spot as the next available spot
    }

    // Pushes 'X' into the Mth stack.
    // Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m) {
        // Check if there is space to push into the stack
        if (freeSpot == -1)
            return false;

        int index = freeSpot;
        freeSpot = next[index]; // Move to the next available spot

        arr[index] = x;         // Store the element in the array
        next[index] = top[m - 1]; // Link the new element to the previous top
        top[m - 1] = index;      // Update the top to the new element

        return true;
    }

    // Pops top element from Mth Stack.
    // Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m) {
        // Check if the stack is empty
        if (top[m - 1] == -1)
            return -1;

        int index = top[m - 1];    // Get the index of the top element
        top[m - 1] = next[index];  // Update top to the next element
        next[index] = freeSpot;    // Link the popped element to the next available spot
        freeSpot = index;          // Update the next available spot to the popped element

        return arr[index];         // Return the popped element
    }
};

// Note: The above code assumes 1-indexed stacks. If you want 0-indexed stacks, adjust indices accordingly.
