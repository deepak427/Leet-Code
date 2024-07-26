class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> v(nums.size());
        vector<int> result;

        for(int &value: nums){
            if(v[value-1]==1){
                result.push_back(value);
            }else{
                v[value-1]++;
            }
        }

        return result;

    }
};