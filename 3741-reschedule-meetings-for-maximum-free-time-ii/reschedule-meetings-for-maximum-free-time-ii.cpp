class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> FreeArray;
        FreeArray.push_back(startTime[0]);
        for(int i=1; i<startTime.size(); i++){
            FreeArray.push_back(startTime[i]-endTime[i-1]);
        }
        FreeArray.push_back(eventTime - endTime[endTime.size()-1]);
        int n = FreeArray.size();
        vector<int> maxRightfree(n,0);
        vector<int> maxLeftfree(n,0);

        for(int i = n-2; i>=0; i--){
            maxRightfree[i] = max(maxRightfree[i+1], FreeArray[i+1]);
        }

        for(int i = 1; i<n; i++){
            maxLeftfree[i] = max(maxLeftfree[i-1], FreeArray[i-1]);
        }

        int result = 0;
        for(int i = 1; i<n; i++){
            int currEvent = endTime[i-1] - startTime[i-1];

            if(currEvent <= max(maxLeftfree[i-1], maxRightfree[i])){
                result = max(result, FreeArray[i-1]+currEvent+FreeArray[i]);
            }

            result = max(result, FreeArray[i-1] + FreeArray[i]);
        }

        return result;
    }
};