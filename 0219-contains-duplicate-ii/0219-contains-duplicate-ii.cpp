class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> nums_m;
        for(int i = 0; i< nums.size(); ++i){
            if( nums_m.find(nums[i]) != nums_m.end()) {
                if(i - nums_m.find(nums[i])->second <=k){
                    return true;
                }
            }
            nums_m[nums[i]] = i;
        }
        return false;

    }
};