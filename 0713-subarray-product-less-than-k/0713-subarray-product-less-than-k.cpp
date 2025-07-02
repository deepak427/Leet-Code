class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, end = 0, product = 1, output = 0;

        if(k == 0){
            return 0;
        }

        while(start < nums.size()){
            product = product*nums[end];
            if(product < k){
                ++output;
                if(end != (nums.size()-1)){
                    ++end;
                }else{
                    product = 1;
                    ++start;
                    end = start;
                }
            }else{
                product = 1;
                ++start;
                end = start;
            }
        }

        return output;
    }
};