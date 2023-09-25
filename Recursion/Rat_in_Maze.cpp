class Solution {
private:
    // Helper function to check if it's safe to move to the cell (x, y)
    bool isSafe(int x, int y, int n, vector<vector<int>>& visited, vector<vector<int>>& m) {
        // Check if the cell is within the grid boundaries, unvisited, and not blocked.
        if (x >= 0 && x < n && y >= 0 && y < n && visited[x][y] == 0 && m[x][y] == 1) {
            return true;
        }
        return false;
    }

    // Recursive function to find all possible paths
    void findPaths(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>>& visited, string path) {
        // Base case: If we reach the destination (bottom-right cell), add the path to the answer.
        if (x == n - 1 && y == n - 1) {
            ans.push_back(path);
            return;
        }

        // Mark the current cell as visited.
        visited[x][y] = 1;

        // Try moving down (D), left (L), right (R), and up (U) if it's safe.
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        char dir[] = {'D', 'L', 'R', 'U'};

        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isSafe(newX, newY, n, visited, m)) {
                path.push_back(dir[i]); // Append the direction to the path.
                findPaths(m, n, ans, newX, newY, visited, path);
                path.pop_back(); // Backtrack by removing the last direction.
            }
        }

        // Mark the current cell as unvisited (backtrack).
        visited[x][y] = 0;
    }

public:
    vector<string> findPath(vector<vector<int>>& m, int n) {
        vector<string> ans; // Stores the found paths.
        if (m[0][0] == 0) return ans; // If the source cell is blocked, return an empty answer.

        int srcX = 0; // Starting row.
        int srcY = 0; // Starting column.

        // Initialize a visited matrix with all cells initially unvisited.
        vector<vector<int>> visited(n, vector<int>(n, 0));

        string path = ""; // Initialize the path string.
        
        // Call the recursive function to find paths.
        findPaths(m, n, ans, srcX, srcY, visited, path);
        
        sort(ans.begin(), ans.end()); // Sort the paths lexicographically.

        return ans;
    }
};
