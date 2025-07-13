class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k == 0) return nums;
        long long c_sum = 0;
        vector<int> kAverage(nums.size(), -1);

        for(int i = 0; i < nums.size(); ++i){
            c_sum+=nums[i];

            if(i == 2*k){
                kAverage[i-k] = c_sum/(2*k + 1);
            }

            if(i > 2*k){
                c_sum-=nums[i-(2*k)-1];
                kAverage[i-k] = c_sum/(2*k + 1);
            }
        }

        return kAverage;
    }
};