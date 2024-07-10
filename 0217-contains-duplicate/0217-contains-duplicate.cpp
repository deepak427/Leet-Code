class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> d_map;
        for(int i = 0; i <nums.size();++i ){
            d_map[nums[i]] = i;
        }
        if(d_map.size() == nums.size()){
            return false;
        }else{
            return true;
        }
    }
};