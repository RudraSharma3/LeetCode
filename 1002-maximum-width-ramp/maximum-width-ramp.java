class Solution {
    public int maxWidthRamp(int[] nums) {
        int n = nums.length;
        // Monotonic decreasing stack to store indices
        Stack<Integer> stack = new Stack<>();
        
        // Step 1: Build the monotonic decreasing stack
        for (int i = 0; i < n; i++) {
            // We only push the index if the stack is empty or the current value is less than the value at the top of the stack
            if (stack.isEmpty() || nums[stack.peek()] > nums[i]) {
                stack.push(i);
            }
        }
        
        // Step 2: Traverse the array from the end and find the max ramp width
        int maxRamp = 0;
        for (int j = n - 1; j >= 0; j--) {
            // While the stack is not empty and the value at the top of the stack is less than or equal to nums[j],
            // we calculate the ramp width and update the result.
            while (!stack.isEmpty() && nums[stack.peek()] <= nums[j]) {
                maxRamp = Math.max(maxRamp, j - stack.pop());
            }
        }
        
        return maxRamp;
    }
}
