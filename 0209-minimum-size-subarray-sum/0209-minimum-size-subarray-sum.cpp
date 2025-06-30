class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int start = 0;
        int min_length = 0;
        int sum = 0;

        for(int end = 0; end < nums.size(); ++end){
            sum = sum + nums[end];

            while(sum >= target){
                if(((end-start+1) < min_length) || (min_length == 0)){
                    min_length = end-start+1;
                    if(min_length==1) return min_length;
                }
                sum=sum-nums[start];
                ++start;
            }
        }

        return min_length;
    }
};