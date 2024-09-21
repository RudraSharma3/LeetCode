class Solution {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> result = new ArrayList<>();
        // Start DFS from every digit from 1 to 9
        for (int i = 1; i <= 9; i++) {
            dfs(i, n, result);
        }
        return result;
    }

    // Depth First Search function
    private void dfs(int current, int n, List<Integer> result) {
        if (current > n) {
            return; // If current number exceeds n, stop the recursion.
        }

        result.add(current); // Add the current number to the result.

        // Try to append digits 0 to 9 to the current number.
        for (int i = 0; i <= 9; i++) {
            int next = current * 10 + i; // Generate the next number
            if (next > n) {
                return; // If the next number exceeds n, stop the recursion.
            }
            dfs(next, n, result); // Continue the DFS with the new number.
        }
    }
}
