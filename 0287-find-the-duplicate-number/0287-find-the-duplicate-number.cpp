class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(nums.size()); 

        for(int &value: nums){
            if(v[value] == 1){
                return value;
            }
            v[value] = 1;
        }

        return -1;
    }
};