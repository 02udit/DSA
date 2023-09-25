#include <bits/stdc++.h>

// Function to count distinct ways to climb nStairs using recursion
int countDistinctWays(int nStairs) {
    // Base cases:
    // If there are 0 stairs, there's 1 way (no need to climb).
    if (nStairs == 0) {
        return 1;
    }
    // If there are negative stairs, there's no way to climb.
    else if (nStairs < 0) {
        return 0;
    }

    // Recursive case:
    // Calculate the distinct ways to climb nStairs by summing two cases:
    // 1. Climbing 1 stair and then counting distinct ways for (nStairs-1).
    // 2. Climbing 2 stairs and then counting distinct ways for (nStairs-2).
    int ans = countDistinctWays(nStairs - 1) + countDistinctWays(nStairs - 2);
    
    return ans; // Return the total distinct ways to climb nStairs.
}


// this code can be optimized using dynamic programming

