class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start = 0, end = 0, product = 1, output = 0;

        if((k == 0) || (k == 1)){
            return 0;
        }

        while(end < nums.size()){
            product = product*nums[end];
            if(product < k){
                output = output + (end-start) + 1;
                ++end;
            }else{
                if(start == end){
                    product = (product/nums[start]);
                    ++end;
                }else{
                    product = (product/nums[start])/nums[end];
                }
                ++start;
            }
        }

        return output;
    }
};