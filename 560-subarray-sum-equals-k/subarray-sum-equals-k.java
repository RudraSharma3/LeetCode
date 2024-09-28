class Solution {
    public int subarraySum(int[] nums, int k) {
      HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1); // Base case: there's one way to get a sum of 0, by taking no elements
        
        int count = 0;
        int cumulativeSum = 0;
        
        for (int num : nums) {
            cumulativeSum += num; // Update cumulative sum
            
            // Check if there is a subarray ending at this index that sums to k
            if (map.containsKey(cumulativeSum - k)) {
                count += map.get(cumulativeSum - k);
            }
            
            // Store/update the frequency of this cumulative sum in the map
            map.put(cumulativeSum, map.getOrDefault(cumulativeSum, 0) + 1);
        }
        
        return count;
    }
}