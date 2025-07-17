class Solution 
{
public:
    int maximumLength(vector<int>& nums, int k) 
    {
        // Step 1: Create a 2D DP table to track remainder transitions
        vector<vector<int>> dp(k, vector<int>(k, 0)); // dp[prev_rem][curr_rem]
        int maxLength = 0;

        // Step 2: Loop through each number in the array
        for (int num : nums) 
        {
            int current_rem = num % k;

            // Step 3: Try to extend previously formed sequences
            for (int prev_rem = 0; prev_rem < k; ++prev_rem) 
            {
                // Step 4: Extend the sequence from (current_rem → prev_rem) to (prev_rem → current_rem)
                dp[prev_rem][current_rem] = dp[current_rem][prev_rem] + 1;

                // Step 5: Update the maximum length found so far
                maxLength = max(maxLength, dp[prev_rem][current_rem]);
            }
        }

        // Step 6: Return the result
        return maxLength;
    }
};