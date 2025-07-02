class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;

        int product = 1, count = 0, start = 0;

        for (int end = 0; end < nums.size(); ++end) {
            product *= nums[end];

            while (product >= k) {
                product /= nums[start];
                ++start;
            }

            count += (end - start + 1);  // All subarrays ending at `end` with start from [start, end]
        }

        return count;
    }
};
