class Solution {
public:
    char nextChar(char c) {
        if (c == 'z') {
            return 'a';
        } else {
            return c + 1;
        }
    }

    char kthCharacter(int k) {
        string word = "a";
        while (word.size() < k) {
            string temp = "";
            for (char c : word) {
                temp += nextChar(c);
            }
            word += temp;
        }
        return word[k - 1];
    }
};