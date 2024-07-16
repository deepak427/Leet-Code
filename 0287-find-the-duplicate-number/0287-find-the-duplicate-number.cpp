class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> nums_d = nums;
        sort(nums_d.begin(), nums_d.end()); 

        for(int i = 0; i< nums_d.size(); ++i){
            if(nums_d[i]==nums_d[i+1]){
                return nums_d[i];
            }
        }

        return -1;
    }
};