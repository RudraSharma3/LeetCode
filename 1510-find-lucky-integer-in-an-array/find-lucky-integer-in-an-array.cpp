class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;

        for (int num : arr) {
            freq[num]++;
        }

        int result = -1;
        for (auto& entry : freq) {
            if (entry.first == entry.second) {
                result = max(result, entry.first);
            }
        }

        return result;
    }
};