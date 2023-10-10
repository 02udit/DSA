class Solution {
private:
    // Function to check if person a knows person b
    bool knows(vector<vector<int>>& M, int a, int b, int n) {
        return M[a][b] == 1;
    }

public:
    // Function to find the celebrity in the party
    int celebrity(vector<vector<int>>& M, int n) {
        stack<int> s;

        // Push all people onto the stack
        for (int i = 0; i < n; i++) {
            s.push(i);
        }

        // Elimination loop to find potential celebrity
        while (s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();

            if (knows(M, a, b, n)) {
                // If a knows b, a cannot be the celebrity, so push b back onto the stack
                s.push(b);
            } else {
                // If a doesn't know b, b cannot be the celebrity, so push a back onto the stack
                s.push(a);
            }
        }

        // The remaining person in the stack is a potential celebrity
        int celeb = s.top();

        // Check both row and column conditions in a single loop
        for (int i = 0; i < n; i++) {
            // If the potential celebrity knows someone or someone doesn't know the potential celebrity,
            // then the potential celebrity is not a celebrity, return -1
            if (i != celeb && (M[celeb][i] == 1 || M[i][celeb] == 0)) {
                return -1;
            }
        }

        // If no issues found, the potential celebrity is the celebrity
        return celeb;
    }
};
