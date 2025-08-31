class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int start = 0, res = 0, diff;
        for(int i = 1; i < nums.size(); ++i){
            int cDiff = nums[i]-nums[i-1];
            if(i-start+1<3){
                diff=cDiff;
                continue;
            }
            if(cDiff==diff) res+=i-start-1;
            else{
                diff=cDiff;
                start=i-1;
            }
        }

        return res;
    }
};