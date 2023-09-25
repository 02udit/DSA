class Solution {
public:
    // Function to calculate the nth Fibonacci number using recursion
    int fib(int n) {
        // Base cases: Fibonacci numbers for n = 0 and n = 1 are 0 and 1, respectively
        if (n == 0) {
            return 0;
        } else if (n == 1) {
            return 1;
        }

        // Recursive case:
        // Calculate the nth Fibonacci number by summing the (n-1)th and (n-2)th Fibonacci numbers
        // Recursively call the fib function to calculate these two numbers
        // This approach follows the Fibonacci sequence definition
        return fib(n - 1) + fib(n - 2);
    }
};
