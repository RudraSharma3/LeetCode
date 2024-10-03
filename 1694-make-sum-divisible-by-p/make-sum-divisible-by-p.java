import java.util.HashMap;

class Solution {
    public int minSubarray(int[] nums, int p) {
        // Step 1: Calculate the total sum of the array
        long totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }

        // Step 2: Compute the remainder when the total sum is divided by p
        int remainder = (int) (totalSum % p);
        // If the total sum is already divisible by p, return 0
        if (remainder == 0) return 0;

        // Step 3: Use a HashMap to store the mod values of prefix sums
        HashMap<Integer, Integer> prefixModMap = new HashMap<>();
        prefixModMap.put(0, -1);  // To handle the case when we can remove a prefix directly.

        long currentSum = 0;
        int minLength = nums.length;

        // Step 4: Iterate through the array
        for (int i = 0; i < nums.length; i++) {
            currentSum += nums[i];
            int currentMod = (int) (currentSum % p);

            // We are looking for (currentMod - remainder) % p
            int targetMod = (currentMod - remainder + p) % p;

            if (prefixModMap.containsKey(targetMod)) {
                int subarrayLength = i - prefixModMap.get(targetMod);
                minLength = Math.min(minLength, subarrayLength);
            }

            // Store the current prefix modulo with its index
            prefixModMap.put(currentMod % p, i);
        }

        // If we didn't find a valid subarray to remove, return -1
        return minLength == nums.length ? -1 : minLength;
    }
}
