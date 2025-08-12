class Solution {
public:
    bool isFeasible(long long speed, vector<int> &piles, int h){
        for(int pile: piles){
            h-=static_cast<int>(ceil(pile/static_cast<double>(speed)));
        }
        return h>=0;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long low = 1;
        long long high = *max_element(piles.begin(), piles.end());

        while(low<high){
            long long mid = low+(high-low)/2;
            if(isFeasible(mid, piles, h)) high=mid;
            else low=mid+1;
        }

        return high;
    }
};