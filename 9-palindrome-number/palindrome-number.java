class Solution {
    public boolean isPalindrome(int x) {
        String str = Integer.toString(x);
        char[] char1 = str.toCharArray();
        char[] y = new char[char1.length];
        for (int i = 0; i < char1.length; i++) {
            y[i] = char1[char1.length - 1 - i];
        }
        if (Arrays.equals(char1, y)) {
            return true;
        } else {
            return false;
        }
    }
}