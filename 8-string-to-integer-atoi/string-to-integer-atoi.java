public class Solution {
    public int myAtoi(String s) {
        int i = 0, n = s.length();
        int sign = 1;
        int result = 0;
        int INT_MAX = Integer.MAX_VALUE;
        int INT_MIN = Integer.MIN_VALUE;

        // Step 1: Ignore leading whitespaces
        while (i < n && s.charAt(i) == ' ') {
            i++;
        }

        // Step 2: Check for the sign
        if (i < n && (s.charAt(i) == '+' || s.charAt(i) == '-')) {
            sign = (s.charAt(i) == '-') ? -1 : 1;
            i++;
        }

        // Step 3: Convert digits to integer
        while (i < n && Character.isDigit(s.charAt(i))) {
            int digit = s.charAt(i) - '0';

            // Step 4: Handle overflow and underflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        // Step 5: Return the final result with sign
        return result * sign;
    }
}