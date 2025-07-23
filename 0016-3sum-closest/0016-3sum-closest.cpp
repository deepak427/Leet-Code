class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int threeSum = 0, min_diff = INT_MAX;

        for (int i = 0; i < nums.size(); ++i) {
            int l_target = target - nums[i];

            int start = i + 1;
            int end = nums.size() - 1;
            while (start < end) {
                int twoSum = nums[start] + nums[end];
                if(abs(l_target-twoSum) < min_diff){
                    min_diff = abs(l_target-twoSum);
                    threeSum = nums[i]+twoSum;
                }
                if (twoSum < l_target)
                    ++start;
                else
                    --end;
            }
        }

        return threeSum;
    }
};