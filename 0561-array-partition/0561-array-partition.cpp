class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int max_sum = 0;
        sort(nums.begin(), nums.end());

        for (int i = nums.size() - 2; i >= 0; i = i - 2) {
            max_sum += nums[i];
        }

        return max_sum;
    }
};