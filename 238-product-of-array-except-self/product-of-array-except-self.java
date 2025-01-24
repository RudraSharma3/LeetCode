class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] answer = new int[nums.length];
        answer[0] = 1;
        for (int i = 1; i < nums.length; i++) {
            answer[i] = nums[i - 1] * answer[i - 1];
        }
        int right = 1;
        for (int i = nums.length - 1; i >= 0; i--) {
            answer[i] = answer[i] * right;
            right *= nums[i];
        }
        return answer;
    }
}