class Solution {
public:
    // Helper function to generate subsets recursively
    void generateSubsets(vector<int>& nums, vector<int>& currentSubset, int index, vector<vector<int>>& subsets) {
        // Base case: If the current index is equal to the size of the nums array, we've formed a subset.
        if (index == nums.size()) {
            subsets.push_back(currentSubset); // Add the current subset to the result.
            return;
        }

        // Exclude the current element from the subset and move to the next index.
        generateSubsets(nums, currentSubset, index + 1, subsets);

        // Include the current element in the subset and move to the next index.
        currentSubset.push_back(nums[index]); // Include the current element.
        generateSubsets(nums, currentSubset, index + 1, subsets);

        // After both recursive calls, the current element will be excluded in 'currentSubset.'
        currentSubset.pop_back(); // Remove the last element to backtrack.
    }

    // Function to generate all possible subsets of nums.
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets; // Store the generated subsets.
        vector<int> currentSubset;   // Store the current subset being generated.
        int index = 0;              // Start from the beginning of the nums array.

        // Start generating subsets using the helper function.
        generateSubsets(nums, currentSubset, index, subsets);

        return subsets; // Return the final list of subsets.
    }
};
