class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        result.push_back(s[0]);
        int freq = 1; //s[0] already inserted in string so 1 frequency 
        for(int i = 1; i < s.length(); i++){
            if(s[i] == result.back()){
                freq++;
                if(freq < 3){
                    result.push_back(s[i]);
                }
            }else{
                result.push_back(s[i]);
                freq = 1; //next char is new so frequency becomes 1
            }
        }
        return result;
    }
};