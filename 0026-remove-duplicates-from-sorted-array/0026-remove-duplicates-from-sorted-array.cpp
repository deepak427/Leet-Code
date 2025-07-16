class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for(int end = 1; end < nums.size(); ++end){
            if(nums[end] == nums[end-1]){
                nums.erase(nums.begin()+end);
                --end;
            }
        }

        return nums.size();
    }
};