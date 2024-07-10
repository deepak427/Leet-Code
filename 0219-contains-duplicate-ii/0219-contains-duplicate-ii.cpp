class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int>> nums_m;
        for(int i = 0; i< nums.size(); ++i){
            if( nums_m.find(nums[i]) != nums_m.end()) {
                for(auto &value: nums_m[nums[i]]){
                    if(abs((value - i)) <=k || abs(( i -value)) <=k){
                        return true;
                    }
                }
                nums_m[nums[i]].push_back(i);
            }else {
                nums_m[nums[i]] = {i};
            }
        }
        return false;

    }
};