class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int profit = 0;

        for(int &value: prices){
            if(value < buy){
                buy = value;
                continue;
            }
            if((value-buy) > profit){
                profit = (value-buy);
            }
        }

        return profit;
    }
};