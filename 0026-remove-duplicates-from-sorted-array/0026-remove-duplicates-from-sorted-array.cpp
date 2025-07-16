class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int start = 1, size = 1;

        for(int end = 1; end < nums.size(); ++end){
            if(nums[end] != nums[end-1]){
                nums[start] = nums[end];
                ++start;
                ++size;
            }
        }

        return size;
    }
};