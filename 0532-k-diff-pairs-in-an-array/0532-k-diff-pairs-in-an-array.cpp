class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int start = 0, diffPairs = 0;
        for(int i = 1; i < nums.size(); ++i){
            while(nums[i]-nums[start]>k) ++start;
            if(nums[i]-nums[start]==k && i!=start){
                ++diffPairs;
                while(i+1<nums.size() && nums[i+1]==nums[i]) ++i;
            }
        }

        return diffPairs;
    }
};