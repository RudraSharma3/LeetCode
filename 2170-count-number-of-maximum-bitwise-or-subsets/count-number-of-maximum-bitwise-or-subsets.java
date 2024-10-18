class Solution {
    // Method to calculate the maximum OR value and count the subsets with this OR
    public int countMaxOrSubsets(int[] nums) {
        int maxOr = 0;
        
        // Step 1: Calculate the maximum possible OR value by OR-ing all elements of the array
        for (int num : nums) {
            maxOr |= num;  // This will give the overall maximum OR possible
        }
        
        // Step 2: Use backtracking to count subsets whose OR is equal to maxOr
        return countSubsets(nums, 0, 0, maxOr);
    }
    
    // Helper method to count subsets with the desired OR value
    private int countSubsets(int[] nums, int index, int currentOr, int maxOr) {
        // If we've processed all elements
        if (index == nums.length) {
            // If the OR of the current subset equals the max OR, count it
            return currentOr == maxOr ? 1 : 0;
        }
        
        // Step 3: Two choices for each element, either include it in the subset or exclude it
        
        // Option 1: Exclude the current element
        int exclude = countSubsets(nums, index + 1, currentOr, maxOr);
        
        // Option 2: Include the current element
        int include = countSubsets(nums, index + 1, currentOr | nums[index], maxOr);
        
        // Return the total count from both choices
        return exclude + include;
    }
}
