class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> um;
        long long maxSum = 0L, currSum = 0L;
        for (int i = 0, start = 0; i < nums.size(); ++i) {
            while (um.find(nums[i]) != um.end() && um[nums[i]] >= start)
                currSum -= nums[start++];
            currSum += nums[i];
            um[nums[i]] = i;
            if (i - start + 1 == k){
                maxSum = max(maxSum, currSum);
                currSum-=nums[start++];
            }
        }

        return maxSum;
    }
};