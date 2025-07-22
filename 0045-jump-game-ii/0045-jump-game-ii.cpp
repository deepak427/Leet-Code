class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()==1) return 0;
        int t_jumps = 0;

        for(int n = 0; n< nums.size(); ++n){
            int l_max = INT_MIN;
            int curr = nums[n];
            int to_jump = n;

            for(int i = 0; i < curr; ++i){
                if(n+1==nums.size()-1) return ++t_jumps;
                if(l_max < nums[++n]+i){
                    l_max = nums[n]+i;
                    to_jump = n;
                }
            }
            n=to_jump-1;
            ++t_jumps;
        }

        return t_jumps;
    }
};