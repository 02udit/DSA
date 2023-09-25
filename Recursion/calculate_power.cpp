#include<bits/stdc++.h>
using namespace std;

// Function to calculate the power of a number using recursion
int power(int a, int b) {
    // Base cases:
    // If the exponent (b) is 0, the result is 1.
    if (b == 0) {
        return 1;
    }
    // If the exponent is 1, the result is the base (a) itself.
    else if (b == 1) {
        return a;
    }

    // Calculate halfAns by recursively computing the power of a raised to b/2.
    int halfAns = power(a, b / 2);

    // If the exponent (b) is odd (b is odd when b & 1 is true), compute a^b using a*halfAns*halfAns.
    if (b & 1) {
        return a * halfAns * halfAns;
        // a*(a^(b/2))*(a^(b/2))== a*(a^(b/2))^2 == (a^b) -->when b is odd
    }
    // If the exponent is even, compute a^b using halfAns*halfAns.
    else {
        return halfAns * halfAns;

        // (a^(b/2))*(a^(b/2))== (a^(b/2))^2 == (a^b) -->> when b is even  
    }
}

int main() {
    int a = 3;   // Base
    int b = 11;  // Exponent

    // Call the power function to calculate a^b.
    int ans = power(a, b);

    // Print the result.
    cout << a << " to the power " << b << " is " << ans << endl;

    return 0;
}
