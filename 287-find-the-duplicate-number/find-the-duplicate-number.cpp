class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int i=0;
        int x = nums[0];
        while(x!=0){
            x = nums[i];
            nums[i]=0;
            if(x!=0){
                i = x;
            }
        }
        return i;
    }
};