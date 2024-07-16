class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> nums_m; 

        for(int &value: nums){
            nums_m[value]++;
        }

        for(auto &value: nums_m){
            if(value.second > 1 ){
                return value.first;
            }
        }

        return -1;
    }
};