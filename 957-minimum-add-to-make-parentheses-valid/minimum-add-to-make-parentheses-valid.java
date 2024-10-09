class Solution {
    public int minAddToMakeValid(String s) {
        // To track unbalanced parentheses
        int open = 0, close = 0;
        
        // Iterate through the string
        for (char c : s.toCharArray()) {
            if (c == '(') {
                // Track the need for a closing parenthesis
                open++;
            } else {
                if (open > 0) {
                    // A matched pair of parentheses
                    open--;
                } else {
                    // A closing parenthesis without a matching opening
                    close++;
                }
            }
        }
        
        // Total unbalanced parentheses (open + close)
        return open + close;
    }
}
