class Solution {
    public int removeDuplicates(int[] nums) {
         if (nums.length == 0) return 0; // Handle edge case for empty array
        
        int slow = 0; // Pointer for the last unique element
        
        for (int fast = 1; fast < nums.length; fast++) {
            if (nums[fast] != nums[slow]) { // Found a new unique element
                slow++; // Move slow pointer forward
                nums[slow] = nums[fast]; // Update the position with the new unique element
            }
        }
        
        return slow + 1; 
    }
}