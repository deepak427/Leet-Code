class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                int start = mid, end = mid;
                while(start>=0 && nums[start]==target){
                    --start;
                }
                while(end<nums.size() && nums[end]==target){
                    ++end;
                }
                return {start+1,end-1};
            }
            if (nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }

        return {-1, -1};
    }
};