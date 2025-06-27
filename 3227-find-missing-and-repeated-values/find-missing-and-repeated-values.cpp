class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int n2 = n * n;

        vector<int> count(n2 + 1, 0);  
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                count[grid[i][j]]++;
            }
        }

        int r = -1, m = -1;
        for (int i = 1; i <= n2; i++) {
            if (count[i] == 2) r = i;
            if (count[i] == 0) m = i;
        }
        return {r, m};
    }
};
