class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int n = nums.size();

        for (int num : nums) {
            freq[num]++;

          
            if (freq[num] > n / 2) {
                return num;
            }
        }
        return -1; 
    }
};
