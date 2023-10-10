#include <bits/stdc++.h>
using namespace std;

// Define a Stack class
class Stack
{
public:
    int data;         // Data of the stack node
    Stack *top;       // Pointer to the top of the stack
    Stack *head;      // Pointer to the head of the stack (the first node)
    Stack *next;      // Pointer to the next node in the stack

    // Default constructor to initialize top and head to NULL
    Stack()
    {
        top = NULL;
        head = NULL;
    }

    // Parameterized constructor to create a stack node with given data
    Stack(int data)
    {
        this->data = data;
        next = NULL;
    }

    // Function to push a new node with given data onto the stack
    void push(int data)
    {
        // Create a new node with the given data
        Stack *temp = new Stack(data);

        // If the stack is empty, set both top and head to the new node
        if (top == NULL)
        {
            top = temp;
            head = temp;
        }
        else
        {
            // Otherwise, add the new node to the top of the stack and update top
            top->next = temp;
            top = temp;
        }
    }

    // Function to pop the top node from the stack
    void pop()
    {
        if (top == head)
        {
            // If there's only one node in the stack, set top to NULL
            top = NULL;
        }
        else if (top != NULL)
        {
            // If there are multiple nodes, traverse the stack to find the new top
            Stack *temp = head;
            while (temp->next != top)
            {
                temp = temp->next;
            }
            top = temp;
            top->next = NULL;
        }
        else
        {
            // Display an error message if attempting to pop from an empty stack
            cout << "Stack underflow " << endl;
        }
    }

    // Function to peek at the data of the top node in the stack
    int peek()
    {
        if (top != NULL)
        {
            return top->data;
        }
        else
        {
            // Display an error message if attempting to peek from an empty stack
            cout << "stack is empty " << endl;
            return -1;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        if (top == NULL)
            return true;
        else
            return false;
    }
};

// Main function
int main()
{
    // Create an instance of the Stack class
    Stack st;

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
