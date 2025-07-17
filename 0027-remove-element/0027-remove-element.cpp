class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int start = 0, end = nums.size()-1, size = 0;

        while(start <= end){
            while(nums[end]==val){
                --end;
                if(start > end) return size;
            } 
            if(nums[start]==val){
                nums[start]=nums[end];
                --end;
            }
            ++start;
            ++size;
        }

        return size;
    }
};