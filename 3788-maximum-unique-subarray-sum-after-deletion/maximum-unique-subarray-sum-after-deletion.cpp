class Solution {
public:
    int maxSum(vector<int>& nums) {
        int result=INT_MIN,sum=0;
        set<int,greater<int>> s(nums.begin(), nums.end());
        for(int num:s)
        {
            sum+=num;
            result=max(result,sum);
        }
        return result;
    }
};