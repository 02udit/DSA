#include <bits/stdc++.h> 
using namespace std;
// Function to convert a decimal number to a binary string

string toBinary(long long N) {
    string num;

    // Convert N to binary representation
    while (N > 0) {
        int digit = N & 1; // Extract the least significant bit as a digit (0 or 1)
        num.push_back(digit + '0'); // Convert the digit to a character and append it to the string
        N = N >> 1; // Right-shift N to process the next bit
    }

    reverse(num.begin(), num.end()); // Reverse the binary string to obtain the correct representation
    return num;
}

// we can use the below also but it is not optimal-------------->>>>>>>>>>>

/*
string toBinary(long long N) {
    long long temp = N;
    int count = 0;

    // Calculate the number of binary digits needed to represent N
    while (temp != 0) {
        count++;
        temp = temp >> 1;
    }

    string num;

    // Convert N to binary representation
    while (count > 0) {
        int digit = N & 1;
        num.push_back(digit + '0'); // Convert the digit to a character and append it to the string
        N = N >> 1;
        count--;
    }

    reverse(num.begin(), num.end()); // Reverse the binary string
    return num;
}   
*/
// <<<<<<<<<<<<----------------


// Function to check if a string is a palindrome using recursion
bool isPalindrome(string str, int i, int j) {
    // Base case: If the left index (i) is greater than the right index (j),
    // the string is a palindrome, so return true.
    if (i > j) {
        return true;
    }

    // Check if the characters at indices i and j are equal.
    if (str[i] != str[j]) {
        return false; // Return false if they are not equal.
    } else {
        // If the characters are equal, recursively check the rest of the string.
        return isPalindrome(str, i + 1, j - 1);
    }
}

// Function to check if the binary representation of a decimal number is a palindrome
bool checkPalindrome(long long N) {
    string str = toBinary(N); // Convert the decimal number to a binary string

    cout<<str<<endl;
    int i = 0;
    int j = str.length() - 1;

    // Call the isPalindrome function to check if the binary string is a palindrome.
    return isPalindrome(str, i, j);
}

int main() {
    long long N = 9; // Example decimal number

    // Call the checkPalindrome function to check if the binary representation of N is a palindrome.
    if (checkPalindrome(N)) {
        cout << "Binary representation is a palindrome." << endl;
    } else {
        cout << "Binary representation is not a palindrome." << endl;
    }

    return 0;
}
