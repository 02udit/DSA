#include <stack>
#include <string>
using namespace std;

// Function to check if a given expression has valid parentheses
bool isValidParenthesis(string expression) {
    stack<char> s;  // Create a stack to store opening parentheses

    // Iterate through each character in the expression
    for (int i = 0; i < expression.size(); i++) {
        char ch = expression[i];

        // If the character is an opening parenthesis, push it onto the stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else {
            // If the character is a closing parenthesis
            if (!s.empty()) {
                char top = s.top();  // Get the top element of the stack

                // Check if the closing parenthesis matches the corresponding opening parenthesis
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') ||
                    (ch == ']' && top == '[')) {
                    s.pop();  // Pop the matching opening parenthesis from the stack
                } else {
                    return false;  // Mismatched parentheses, return false
                }
            } else {
                return false;  // There is no corresponding opening parenthesis, return false
            }
        }
    }

    // Check if there are any remaining opening parentheses in the stack
    if (s.empty()) {
        return true;  // All parentheses are matched and the stack is empty, return true
    } else {
        return false;  // There are unmatched opening parentheses, return false
    }
}
