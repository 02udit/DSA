class Solution {
public:
    int countPrimes(int n) {
        int count = 0;  // Initialize a counter to keep track of prime numbers
        vector<bool> prime(n + 1, true);  // Create a boolean vector to mark prime numbers
        prime[0] = prime[1] = false;  // 0 and 1 are not prime numbers by definition
        
        // Iterate through numbers from 2 to n-1
        for (int i = 2; i < n; i++) {
            if (prime[i]) {  // If i is marked as prime
                count++;  // Increment the prime count
                // Mark all multiples of i as not prime (they are divisible by i)
                for (int j = 2 * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }
        
        return count;  // Return the count of prime numbers less than n
    }
};


//optimized approach----->>>>



class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0; // There are no prime numbers less than or equal to 2

        vector<bool> isPrime(n, true); // Create a boolean vector to mark prime numbers
        isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime numbers

        // Iterate through numbers from 2 to sqrt(n)
        for (int i = 2; i * i < n; i++) {
            if (isPrime[i]) {
                // Mark multiples of i starting from i^2 as not prime to prevent multiple times marking
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count the prime numbers
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};
```

Optimizations:

1. We check if `n` is less than or equal to 2 at the beginning, and if so, return 0 because there are no prime numbers less than or equal to 2.

2. We use `isPrime` vector of size `n` instead of `n+1` to represent whether numbers from 0 to `n-1` are prime.

3. We iterate only up to the square root of `n` because any factor larger than the square root must be a multiple of a smaller prime.
For example, consider n = 36. Its square root is sqrt(36) = 6. If n has a prime factor larger than 6 (e.g., 7), it must also have a corresponding factor smaller than 6 (e.g., 2). Therefore, if we've already marked multiples of 2, there's no need to check multiples of 7 because they have already been marked by 2.

4. We use the sieve of Eratosthenes algorithm to efficiently mark multiples of prime numbers as not prime.

5. Finally, we count the prime numbers by iterating through the `isPrime` vector and return the count.

This optimized code reduces unnecessary iterations and is more efficient for larger values of `n`.
