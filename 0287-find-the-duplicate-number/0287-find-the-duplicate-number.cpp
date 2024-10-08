class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(nums.size()); 

        for(int i = 0; i< nums.size(); ++i){
            if(v[nums[i]] == 1){
                return nums[i];
            }
            v[nums[i]] = 1;
        }

        return -1;
    }
};