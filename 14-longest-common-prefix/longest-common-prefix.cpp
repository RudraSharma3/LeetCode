class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        string prefix = strs[0];
        for(int i=0; i<strs.size(); i++){
            int j=0;
            while(j<prefix.size() && j<strs[i].size() && prefix[j]==strs[i][j]){
                j++;
            }
            prefix = prefix.substr(0,j);
            if(prefix.empty()) return "";
        }
        return prefix;
    }
};