class Solution {
    public int[] searchRange(int[] nums, int target) {
        int result[] = {-1,-1};
        result[0] = findFirst(nums, target);
        result[1] = findLast(nums, target);
        return result;
    }
    private int findFirst(int[] nums, int target){
        int l=0, h = nums.length-1;
        int first = -1;
        while(l<=h){
            int mid = l +(h-l)/2;
            if(nums[mid]==target){
                first = mid;
                h = mid - 1;
            }else if (nums[mid]<target){
                l = mid + 1;
            }
            else{
                h = mid -1;
            }
        }
        return first;
    }
    private int findLast(int[] nums, int target){
        int l = 0, h = nums.length-1;
        int last = -1;
        while (l<=h){
            int mid = l + (h-l)/2;
            if(nums[mid]==target){
                last = mid;
                l = mid + 1;
            }else if(nums[mid]<target){
                l = mid + 1;
            }else{
                h = mid - 1;
            }
        }
        return last;
    }
}