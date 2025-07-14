class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int, int> um;
        int min_card = INT_MAX;

        for(int i = 0; i < cards.size(); ++i){
            if(um.find(cards[i]) != um.end()){
                min_card = min(min_card, i - um[cards[i]] + 1);
            }

            um[cards[i]] = i;
        }

        if(min_card == INT_MAX) return -1;

        return min_card;
    }
};