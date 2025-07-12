class Solution {
public:
    int solve(vector<int>& nums, int i, int prev_index, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;

        if (dp[i][prev_index + 1] != -1) return dp[i][prev_index + 1];

        int take = 0;
        if (prev_index == -1 || nums[i] > nums[prev_index]) {
            take = 1 + solve(nums, i + 1, i, dp);
        }

        int notTake = solve(nums, i + 1, prev_index, dp);

        return dp[i][prev_index + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(nums, 0, -1, dp);
    }
};
