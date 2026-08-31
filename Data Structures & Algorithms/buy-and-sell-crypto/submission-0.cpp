class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        int minPrice = prices[0];
        for(int i = 1; i < prices.size(); i++){
            int profit = prices[i] - minPrice;
            maxP = max(profit, maxP);
            if(minPrice > prices[i]) minPrice = prices[i];
        }
        return maxP;
    }
};
