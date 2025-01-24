class Solution {
    public int minExtraChar(String s, String[] dictionary) {
         Set<String> wordSet = new HashSet<>();
        for (String word : dictionary) {
            wordSet.add(word);
        }

        int n = s.length();
        // Step 2: Initialize dp array where dp[i] is the min extra characters for s[0:i]
        int[] dp = new int[n + 1]; // dp array size n+1, dp[i] represents the first i characters
        // Initialize dp array, where initially all positions are filled with maximum (i.e., all extra characters)
        for (int i = 0; i <= n; i++) {
            dp[i] = i; // maximum extra chars for i characters is i itself
        }

        // Step 3: Fill dp array
        for (int i = 1; i <= n; i++) {
            // Try breaking the string at every j from 0 to i-1
            for (int j = 0; j < i; j++) {
                String substring = s.substring(j, i);
                if (wordSet.contains(substring)) {
                    dp[i] = Math.min(dp[i], dp[j]); // No extra chars if substring is in dictionary
                } else {
                    dp[i] = Math.min(dp[i], dp[j] + (i - j)); // Consider all characters as extra if not in dictionary
                }
            }
        }

        // Step 4: The result is the minimum number of extra characters for the entire string
        return dp[n];
    }
}