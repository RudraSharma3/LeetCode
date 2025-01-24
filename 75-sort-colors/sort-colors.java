class Solution {
    public void sortColors(int[] nums) {
        int low = 0, mid = 0, high = nums.length - 1;

        // Process the array elements
        while (mid <= high) {
            if (nums[mid] == 0) {
                // Swap nums[low] and nums[mid], then increment low and mid
                swap(nums, low, mid);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                // Move mid pointer forward
                mid++;
            } else {
                // Swap nums[mid] and nums[high], then decrement high
                swap(nums, mid, high);
                high--;
            }
        }
    }

    // Helper function to swap two elements in the array
    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}