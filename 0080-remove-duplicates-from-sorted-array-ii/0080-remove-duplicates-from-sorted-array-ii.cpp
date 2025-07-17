class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> c_nums = nums;
        if(nums.size()==1) return 1;
        int start = 2;

        for(int end = 2; end < c_nums.size(); ++end){
            if((c_nums[end]!=c_nums[end-1]) || (c_nums[end]!=c_nums[end-2])){
                nums[start] = nums[end];
                ++start;
            }
        }

        return start;
    }
};