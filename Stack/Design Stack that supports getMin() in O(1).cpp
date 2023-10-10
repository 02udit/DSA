#include<stack>

class SpecialStack {
    // Define the data members.
	stack<int> s;  // Stack to store elements
    int mini;       // Variable to store the minimum element

    /*----------------- Public Functions of SpecialStack -----------------*/
public:
    // Function to push an element onto the stack
    void push(int data) {
        // For the first element
        if(s.empty()) {
            s.push(data);
            mini = data;
        }
        else {
            // If the data is smaller than the current minimum
         	if(data < mini) {
                s.push(2 * data - mini);  // Store a special value to track the change in minimum
                mini = data;              // Update the minimum
            }   
            else {
                s.push(data);
            }
        }
    }

    // Function to pop the top element from the stack
    int pop() {
        // Check if the stack is empty
        if(s.empty()){
            return -1; // Return -1 if the stack is empty
        }
        
        int curr = s.top(); // Get the top element
        s.pop();            // Pop the top element

        // Check if the current element is greater than the current minimum
        if(curr > mini) {
            return curr; // Return the current element
        }
        else {
            int prevMin = mini;         // Save the previous minimum
            int val = 2 * mini - curr;  // Retrieve the actual value from the special value
            mini = val;                 // Update the minimum
            return prevMin;             // Return the previous minimum
        }
    }

    // Function to get the top element of the stack
    int top() {
        // Check if the stack is empty
        if(s.empty())
            return -1; // Return -1 if the stack is empty
        
        int curr = s.top(); // Get the top element

        // Check if the current element is less than the current minimum
        if(curr < mini) {
            return mini; // Return the current minimum
        }
        else {
            return curr; // Return the current element
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return s.empty(); // Return true if the stack is empty, false otherwise
    }

    // Function to get the minimum element in the stack
    int getMin() {
        // Check if the stack is empty
        if(s.empty())
            return -1; // Return -1 if the stack is empty
        
        return mini; // Return the current minimum
    }  
};
