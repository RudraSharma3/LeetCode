class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;  // Set to store unique elements

        for (int num : nums) {
            if (seen.count(num)) {
                return true;  // Duplicate found
            }
            seen.insert(num);  // Insert current number into the set
        }

        return false;  // No duplicates found
    }
};
