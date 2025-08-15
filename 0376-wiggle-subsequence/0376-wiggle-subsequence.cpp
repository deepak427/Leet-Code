class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int length = 1, inc = -1;

        for(int i = 1; i < nums.size(); ++i){
            if(nums[i]!=nums[i-1]){
                if(inc==-1) ++length;
                else if(nums[i]<nums[i-1]==inc) ++length;
                else continue;
                inc=nums[i]>nums[i-1];
            }
        }

        return length;
    }
};