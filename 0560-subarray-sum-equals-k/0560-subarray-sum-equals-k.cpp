class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int result = 0;
        unordered_map<int, int> sum_m;

        // Initialize map with 0 sum to handle cases where subarray starts from index 0
        sum_m[0] = 1; 

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            // Check if there is a subarray that sums to k
            if (sum_m.find(sum - k) != sum_m.end()) {
                result += sum_m[sum - k]; // Add the frequency of the sum found
            }

            // Increment the frequency of the current sum
            sum_m[sum]++;
        }

        return result;
    }
};
