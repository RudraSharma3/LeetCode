class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> valWithIndex;

        for (int i = 0; i < nums.size(); ++i) {
            valWithIndex.push_back({nums[i], i});
        }
        sort(valWithIndex.begin(), valWithIndex.end(), [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        vector<pair<int, int>> topK(valWithIndex.begin(), valWithIndex.begin() + k);

        sort(topK.begin(), topK.end(), [](const auto& a, const auto& b) {
            return a.second < b.second;
        });
        vector<int> result;
        for (const auto& [val, idx] : topK) {
            result.push_back(val);
        }
        return result;
    }
};