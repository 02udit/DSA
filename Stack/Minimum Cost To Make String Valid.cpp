#include <bits/stdc++.h> 

// Function to find the minimum cost to balance parentheses in a given string
int findMinimumCost(string str) {
  // Check if the length of the string is odd, which implies unbalanced parentheses
  if(str.length() % 2 == 1) {
    return -1;  // Return -1 to indicate invalid input
  }

  stack<char> s;  // Create a stack to store opening braces '{'
  
  // Iterate through each character in the string
  for(int i = 0; i < str.length(); i++) {
      char ch = str[i];
      if(ch == '{') {
        s.push(ch);  // Push an opening brace onto the stack
      } else {
        // If the current character is '}' and there is a matching opening brace on the stack,
        // pop the opening brace, else push the closing brace onto the stack
        if(!s.empty() && s.top() == '{') {
          s.pop();
        } else {
          s.push(ch);
        }
      }
  }

  int a = 0, b = 0;

  // Count the remaining unmatched braces on the stack
  while(!s.empty()) {
    if(s.top() == '{') {
      b++;
    } else {
      a++;
    }
    s.pop();
  }

  // Calculate the minimum cost to balance the parentheses
  int ans = (a + 1) / 2 + (b + 1) / 2;
  return ans;
}
