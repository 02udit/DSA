#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

class Solution {
public:
    // Function to find the first non-repeating character in a string using a queue and hash map
    string FirstNonRepeating(string A) {
        unordered_map<char, int> count;  // Hash map to store the count of each character
        queue<char> q;                  // Queue to maintain the order of characters
        string ans = "";                // Result string to store the first non-repeating characters

        // Iterate through each character in the string
        for (int i = 0; i < A.size(); i++) {
            char ch = A[i];
            count[ch]++;  // Increment the count of the current character
            q.push(ch);   // Push the current character to the queue

            // Check and update the queue until a non-repeating character is found
            while (!q.empty()) {
                if (count[q.front()] > 1) {
                    // If the front character in the queue has a count greater than 1, it's repeating
                    q.pop();  // Remove the front character from the queue
                } else {
                    // If the front character has a count of 1, it's the first non-repeating character
                    ans.push_back(q.front());  // Append the non-repeating character to the result string
                    break;  // Break out of the while loop
                }
            }

            // If the queue is empty, it means no non-repeating character is found so far
            if (q.empty()) {
                ans.push_back('#');  // Append '#' to the result string
            }
        }

        // Return the final result string
        return ans;
    }
};
