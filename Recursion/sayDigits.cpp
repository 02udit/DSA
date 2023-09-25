#include<bits/stdc++.h>
using namespace std;

// Recursive function to print the English word representation of each digit in a number
void functCall(int n, string arr[]) {
    // Base case: If there are no more digits in the number, return.
    if (n == 0) {
        return;
    }

    // Extract the last digit of the number.
    int digit = n % 10;

    // Remove the last digit from the number.
    n = n / 10;

    // Recursively call the function with the remaining number.
    functCall(n, arr);

    // Print the English word representation of the current digit.
    cout << arr[digit] << " ";
}

int main() {
    int n = 951;
    cout << n << " = ";
    
    // An array to store the English word representations of digits from 0 to 9.
    string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    // Call the recursive function to print the English words for each digit.
    functCall(n, arr);   
    cout << endl;
    
    return 0;
}
