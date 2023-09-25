class Solution {
public:
    // Helper function to generate letter combinations recursively
    void generateCombinations(string digits, string currentCombination, string mapping[],int index,vector<string>& ans) {
        // Base case: If the current index is equal to the length of digits, we've formed a combination.
        if (index == digits.length()) {
            ans.push_back(currentCombination); // Add the current combination to the result.
            return;
        }
        
        int num = digits[index] - '0'; // Convert the current digit character to an integer.
        string letters = mapping[num]; // Get the corresponding letters for the digit.
        
        // Iterate through the letters for the current digit.
        for (int i = 0; i < letters.length(); i++) {
            currentCombination.push_back(letters[i]); // Include the current letter.
            
            // Recursively generate combinations for the next index.
            generateCombinations(digits, currentCombination, mapping, index + 1, ans);
            
            currentCombination.pop_back(); // Remove the last letter to backtrack.
        }
    }

    // Function to generate all possible letter combinations from digits.
    vector<string> letterCombinations(string digits) {
        vector<string> ans; // Store the generated combinations.
        
        // Mapping of digits to their corresponding letters.
        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        if (digits.length() == 0) {
            return combinations; // If input is empty, return an empty result.
        }
        
        string currentCombination = ""; // Initialize the current combination.
        int index = 0; // Start from the beginning of the input digits.

        // Start generating combinations using the helper function.
        generateCombinations(digits, currentCombination, mapping, index, ans);

        return ans; // Return the final list of combinations.
    }
};
