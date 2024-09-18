class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit = 0;
       int buyprice = prices[0];
       for(int i=0;i<prices.size();i++){
        if(buyprice>prices[i])
        buyprice = prices[i];

        profit = max(profit, prices[i]-buyprice);
       }
       return profit; 
    }
};