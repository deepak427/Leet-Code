class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> proDif(profit.size());
        for(int i = 0; i < profit.size(); ++i){
            proDif.push_back({profit[i],difficulty[i]});
        }

        sort(proDif.begin(), proDif.end());
        sort(worker.begin(), worker.end());

        long maxProfit = 0;
        for(int i = proDif.size()-1; i>=0; --i){
            auto it = lower_bound(worker.begin(), worker.end(), proDif[i].second);
            if(it!=worker.end()){
                for(int j = worker.size()-1; j >= it-worker.begin();--j){
                    maxProfit+=proDif[i].first;
                    worker.pop_back();
                }
            }
        }

        return maxProfit;
    }
};