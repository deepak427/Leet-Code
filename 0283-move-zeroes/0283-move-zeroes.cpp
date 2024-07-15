class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int a = nums.size();
        for(int i = 0; i< nums.size();++i){
            if(nums[i] == 0){
                if(i ==a ){
                    break;
                }
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                i--;
                a--;
            }
        }
    }
};