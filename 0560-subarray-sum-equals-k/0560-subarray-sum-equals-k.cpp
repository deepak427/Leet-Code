class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        int result = 0;
        unordered_map<int, int> sum_m;

        sum_m[0] = 1; 

        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];

            if (sum_m.find(sum - k) != sum_m.end()) {
                result += sum_m[sum - k]; 
            }

            sum_m[sum]++;
        }

        return result;
    }
};
