#include <bits/stdc++.h>

// Function for modular exponentiation: (x^n) % m
int modularExponentiation(int x, int n, int m) {
    int result = 1; // Initialize the result to 1
    
    // Repeat until n becomes 0
    while (n > 0) {
        if (n & 1) {
            // If the least significant bit of n is 1, multiply result by x and take modulo m (means n is odd)
            result = (1LL * result * x) % m;
        }
        
        // Calculate x^2 and take modulo m
        x = (1LL * x * x) % m;
        
        // Right-shift n by 1 (equivalent to n = n / 2)
        n = n >> 1;
    }
    
    return result; // Return the final result
}
//a^b=(a)^(b/2)^2 if b is even ==(a)^2^(b/2)
//a^b=((a)^(b/2)^2)*(a) if b is odd