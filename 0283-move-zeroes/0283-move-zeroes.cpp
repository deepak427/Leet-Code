class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n_z = 0;
        for(int i = 0; i< nums.size();++i){
            if(nums[i] == 0){
                nums.erase(nums.begin() + i);
                n_z++;
                i--;
            }
        }
        for(int i = 0; i < n_z; ++i){
            nums.push_back(0);
        }
    }
};