class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        
        while (low < high) {
            int mid = low + (high - low) / 2; // Avoid potential overflow in (low + high) / 2
            
            // Compare mid element with the rightmost element
            if (nums[mid] > nums[high]) {
                // Minimum is in the right part
                low = mid + 1;
            } else {
                // Minimum is in the left part or could be the mid itself
                high = mid;
            }
        }
        
        // At the end of the loop, low == high, which is the index of the minimum element
        return nums[low];
    }
};
