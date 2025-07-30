class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        int m = n * 3;
        vector<vector<int>> expanded(m, vector<int>(m, 0));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                char c = grid[i][j];
                if (c == '/') {
                    expanded[i * 3][j * 3 + 2] = 1;
                    expanded[i * 3 + 1][j * 3 + 1] = 1;
                    expanded[i * 3 + 2][j * 3] = 1;
                } else if (c == '\\') {
                    expanded[i * 3][j * 3] = 1;
                    expanded[i * 3 + 1][j * 3 + 1] = 1;
                    expanded[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        vector<vector<bool>> visited(m, vector<bool>(m, false));
        int regions = 0;

        function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || y < 0 || x >= m || y >= m || visited[x][y] || expanded[x][y]) return;
            visited[x][y] = true;
            dfs(x + 1, y);
            dfs(x - 1, y);
            dfs(x, y + 1);
            dfs(x, y - 1);
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < m; ++j) {
                if (!visited[i][j] && expanded[i][j] == 0) {
                    dfs(i, j);
                    regions++;
                }
            }
        }

        return regions;
    }
};