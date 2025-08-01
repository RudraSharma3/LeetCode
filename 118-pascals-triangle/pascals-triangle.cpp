class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        if (numRows > 1) res.push_back({1,1});

        for(int i=2; i<numRows; i++){
            vector<int>v;
            v.push_back(1);
            for(int j=1; j<i; j++){
                  int x = res[i-1][j-1] + res[i-1][j];
                  v.push_back(x);
            }
            v.push_back(1);
            res.push_back(v);
        }
        return res;
    }
};