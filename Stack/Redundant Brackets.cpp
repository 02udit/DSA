#include <bits/stdc++.h> 

// Function to check for redundant brackets in a mathematical expression
bool findRedundantBrackets(string &s) {
    stack<char> st;  // Create a stack to store opening brackets and operators

    // Iterate through each character in the expression
    for(int i = 0; i < s.size(); i++) {
        char ch = s[i];

        // If the character is an opening bracket or an operator, push it onto the stack
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            st.push(ch);
        } else {
            // If the character is a closing bracket
            if (ch == ')') {
                bool isRedundant = true;

                // Check for redundancy until an opening bracket is found
                while (st.top() != '(') {
                    char top = st.top();

                    // If the top of the stack is an operator, the bracket is not redundant
                    if (top == '+' || top == '-' || top == '*' || top == '/') {
                        isRedundant = false;
                    }
                    st.pop();  // Pop the top element
                }

                // Pop the opening bracket
                st.pop();

                // If the bracket is found to be redundant, return true
                if (isRedundant) {
                    return true;
                }
            }
        }
    }

    return false;  // If no redundant brackets are found, return false
}
