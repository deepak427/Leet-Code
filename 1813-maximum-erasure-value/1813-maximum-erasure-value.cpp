class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start = 0, c_sum = 0, sum = 0;
        unordered_map<int, int> um;

        for(int end = 0; end < nums.size(); ++end){
            ++um[nums[end]];
            c_sum+= nums[end];

            if(um.find(nums[end])->second == 1){
                sum = max(sum, c_sum);
            }
            while(um.find(nums[end])->second > 1){
                --um.find(nums[start])->second;
                c_sum-=nums[start];
                ++start;
            }
        }

        return sum;

    }
};