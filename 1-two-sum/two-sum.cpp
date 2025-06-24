class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;  

        for (int i = 0; i < nums.size(); i++) {
            int num_part = target - nums[i];

            if (map.find(num_part) != map.end()) {
                return {map[num_part], i};
            }
            map[nums[i]] = i;
        }
        return {};
    }
};
