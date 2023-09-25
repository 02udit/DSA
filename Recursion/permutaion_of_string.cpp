class Solution {
private:
    // Helper function to generate permutations recursively
    void generatePermutations(vector<int>& nums, vector<vector<int>>& permutations, int index) {
        // Base case: If the current index is equal to the size of nums, we've formed a permutation.
        if (index >= nums.size()) {
            permutations.push_back(nums); // Add the current permutation to the result.
            return;
        }
        
        // Iterate through all elements starting from the current index.
        for (int i = index; i < nums.size(); i++) {
            // Swap the current element with the element at the current index.
            swap(nums[index], nums[i]);
            
            // Recursively generate permutations for the next index.
            generatePermutations(nums, permutations, index + 1);
            
            // Backtrack by swapping the elements back to their original positions.
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations; // Store the generated permutations.
        int index = 0; // Start from the beginning of the nums array.
        
        // Start generating permutations using the helper function.
        generatePermutations(nums, permutations, index);
        
        return permutations; // Return the final list of permutations.
    }
};
