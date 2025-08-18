class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int start = 0;
        long long lK = 0L;
        long long cSum = 0L;
        for(int i = 0; i < nums.size(); ++i){
            cSum+=nums[i];
            while(cSum*(i-start+1)>=k && start<=i){
                cSum-=nums[start++];
            }
            lK+=i-start+1;
        }

        return lK;
    }
};