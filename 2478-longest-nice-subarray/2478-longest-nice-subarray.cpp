class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int start = 0, l_substring = 1;

        for (int end = 1; end < nums.size(); ++end) {
            int brk = start;
            for (int i = start; i < end; ++i) {
                if ((nums[i] & nums[end]) != 0)
                    brk = i + 1;
            }
            start = brk;
            l_substring = max(l_substring, end - start + 1);
        }
        return l_substring;
    }
};