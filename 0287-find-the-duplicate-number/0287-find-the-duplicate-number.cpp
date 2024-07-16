class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        map<int,int> nums_m; 

        for(int &value: nums){
            nums_m[value]++;
            if(nums_m[value] > 1){
                return value;
            }
        }

        return -1;
    }
};