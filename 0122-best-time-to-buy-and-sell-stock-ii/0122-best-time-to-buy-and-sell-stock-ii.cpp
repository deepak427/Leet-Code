class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int sell = prices[0];
        int max_profit = 0;

        for(int i = 1; i <prices.size(); ++i){
            if(prices[i] < prices[i-1]){
                max_profit+=sell-buy;
                buy = prices[i];
                sell=prices[i];
            }else{
                sell=prices[i];
            }
        }

        return max_profit+(sell-buy);
    }
};