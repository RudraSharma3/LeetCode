class Solution {
public:
    int search(vector<int>& nums, int target) {
        //int nums[] = [-1,0,3,5,9,12];
        int low = 0;
        int mid;
        int high = nums.size()-1;
        while(low<=high){
            mid = (low + high)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};