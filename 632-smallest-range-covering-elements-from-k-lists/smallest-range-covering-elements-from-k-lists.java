class Solution {
    public int[] smallestRange(List<List<Integer>> nums) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[0] - b[0]);
        int max = Integer.MIN_VALUE;
        
        // Add the first element of each list to the priority queue
        for (int i = 0; i < nums.size(); i++) {
            pq.add(new int[] {nums.get(i).get(0), i, 0});
            max = Math.max(max, nums.get(i).get(0));
        }
        
        int rangeStart = 0, rangeEnd = Integer.MAX_VALUE;
        
        while (pq.size() == nums.size()) {
            int[] current = pq.poll();
            int min = current[0];
            int i = current[1];
            int j = current[2];
            
            // Update range if the current range is smaller
            if (max - min < rangeEnd - rangeStart) {
                rangeStart = min;
                rangeEnd = max;
            }
            
            // Move to the next element in the current list
            if (j + 1 < nums.get(i).size()) {
                pq.add(new int[] {nums.get(i).get(j + 1), i, j + 1});
                max = Math.max(max, nums.get(i).get(j + 1));
            }
        }
        
        return new int[] {rangeStart, rangeEnd};
    }
}
