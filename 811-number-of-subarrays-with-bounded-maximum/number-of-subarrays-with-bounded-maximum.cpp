class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int n = nums.size(); 
        int start = 0, end = 0;
        int prev = 0, ans = 0;
        while(end < n){
            if(nums[end] >= left && nums[end] <= right){
                prev = end - start + 1;
                ans += prev;
            }else if(nums[end] < left){
                ans += prev;
            }else{
                prev = 0;
                start = end + 1;
            }
            end++;
        }
    return ans;
    }
};