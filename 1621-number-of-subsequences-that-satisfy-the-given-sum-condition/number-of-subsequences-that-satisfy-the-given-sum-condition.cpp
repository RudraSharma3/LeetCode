class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int MOD = 1000000007;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; ++i)
            pow2[i] = (pow2[i - 1] * 2) % MOD;
        int left = 0, right = n - 1;
        int count = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                count = (count + pow2[right - left]) % MOD;
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};