#include <bits/stdc++.h>
using namespace std;

// Define a class named Stack
class Stack
{
public:
    int *arr;    // Pointer to dynamically allocated array to store elements
    int top;     // Index of the top element in the stack
    int size;    // Maximum size of the stack

    // Constructor to initialize the stack with a given size
    Stack(int size)
    {
        this->size = size;
        arr = new int[size];  // Allocate memory for the stack array
        top = -1;             // Initialize top to -1, indicating an empty stack
    }

    // Function to push an element onto the stack
    void push(int element)
    {
        if (size - top > 1)    // Check if there is space in the stack
        {
            top++;            // Increment top
            arr[top] = element; // Add the element to the stack
        }
        else
        {
            cout << "Stack Overflow " << endl;  // Display error message if the stack is full
        }
    }

    // Function to pop an element from the stack
    void pop()
    {
        if (top >= 0)    // Check if the stack is not empty
        {
            top--;       // Decrement top to remove the top element
        }
        else
        {
            cout << "Stack underflow " << endl;  // Display error message if the stack is empty
        }
    }

    // Function to peek at the top element of the stack
    int peek()
    {
        if (top >= 0)    // Check if the stack is not empty
        {
            return arr[top];  // Return the top element
        }
        else
        {
            cout << "stack is empty " << endl;  // Display error message if the stack is empty
            return -1;  // Return a sentinel value to indicate an empty stack
        }
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        if (top == -1)  // If top is -1, the stack is empty
            return true;
        else
            return false;
    }
};

// Main function
int main()
{
    // Create a stack with a maximum size of 5
    Stack st(5);

    // Push elements onto the stack
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    // Display the top element of the stack
    cout << st.peek() << endl;

    // Pop elements from the stack and display the top element after each pop
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();
    cout << st.peek() << endl;
    st.pop();

    // Attempting to pop from an empty stack
    st.pop();

    // Check if the stack is empty and display a corresponding message
    if (st.isEmpty())
    {
        cout << "stack is empty " << endl;
    }
    else
    {
        cout << "stack is not empty " << endl;
    }

    return 0;
}
