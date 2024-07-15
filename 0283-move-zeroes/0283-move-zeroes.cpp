class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int a = nums.size();
        for(int i = 0; i< nums.size();++i){
            if(i ==a ){
                break;
            }
            if(nums[i] == 0){
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                i--;
                a--;
            }
        }
    }
};