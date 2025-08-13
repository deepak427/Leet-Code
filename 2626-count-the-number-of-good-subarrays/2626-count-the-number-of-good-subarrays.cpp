class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0, pairs = 0, start = 0;
        unordered_map<int, int> um;
        ++um[nums[0]];
        for(int i = 1; i < nums.size(); ++i){
            ++um[nums[i]];
            if(um[nums[i]]>1) pairs+=um[nums[i]]-1;
            while(pairs>=k){
                res+=nums.size()-i;
                pairs-=--um[nums[start++]];
            }
        }

        return res;
    }
};