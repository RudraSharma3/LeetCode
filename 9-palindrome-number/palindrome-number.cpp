class Solution {
public:
    bool isPalindrome(int x) {
        int dup = x;
        int rev = 0;
        while(x>0){
            int ld = x % 10;
            x = x/10;
            if((rev > INT_MAX/10) || (rev < INT_MIN/10)) return 0;
            rev = (rev * 10) + ld;
        }
        if(rev == dup) return true;
        else return false;
    }
};