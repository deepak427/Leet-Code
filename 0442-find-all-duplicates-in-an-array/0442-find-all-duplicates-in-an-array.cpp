class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;

        for(int &value: nums){
            int mod = (value-1)%nums.size();
            nums[mod]+=nums.size();
            if(((float)nums[mod]/(float)nums.size())>2.0){
                result.push_back(mod+1);
            }
        }

        return result;

    }
};