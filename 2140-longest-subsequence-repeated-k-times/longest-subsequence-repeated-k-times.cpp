class Solution {
public:
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;
        
        string candidates;
        for (char c = 'a'; c <= 'z'; ++c) {
            if (freq[c] >= k)
                candidates += c;
        }

        queue<string> q;
        string best = "";

        // Start with all 1-char strings
        for (char c : candidates) {
            string temp(1, c);
            q.push(temp);
        }

        while (!q.empty()) {
            int sz = q.size();
            vector<string> level;

            for (int i = 0; i < sz; ++i) {
                string cur = q.front(); q.pop();
                if (isKRepeatedSubsequence(s, cur, k)) {
                    best = cur; // Always overwrite because we're going lex descending
                    for (char c : candidates) {
                        q.push(cur + c);  // BFS for longer string
                    }
                }
            }
        }

        return best;
    }

    // Check if (sub * k) is a subsequence of s
    bool isKRepeatedSubsequence(const string& s, const string& sub, int k) {
        string repeated;
        for (int i = 0; i < k; ++i) repeated += sub;

        int i = 0, j = 0;
        while (i < s.size() && j < repeated.size()) {
            if (s[i] == repeated[j]) j++;
            i++;
        }

        return j == repeated.size();
    }
};
