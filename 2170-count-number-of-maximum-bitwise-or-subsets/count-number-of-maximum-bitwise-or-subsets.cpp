class Solution {
public:
    int n;
    int solve(vector<int>& nums, int& maxOr, int currOr, int idx) {
        if (idx >= n) {
            if (currOr == maxOr) return 1;
            return 0;
        }

        int take = solve(nums, maxOr, nums[idx] | currOr, idx + 1);
        
        int skip = solve(nums, maxOr, currOr, idx + 1);

        return take + skip;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        int maxOr = 0;
        for (int& i : nums) maxOr |= i;

        return solve(nums, maxOr, 0, 0);
    }
};