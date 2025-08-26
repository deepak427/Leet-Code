class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> preFix;
        preFix.push_back(1);
        for(int i = 0; i < nums.size(); ++i){
            preFix.push_back(preFix.back()*nums[i]);
        }
        vector<int> sufFix;
        sufFix.push_back(1);
        for(int i = nums.size()-1; i >=0; --i){
            sufFix.push_back(sufFix.back()*nums[i]);
        }

        vector<int> res;
        for(int i = 0; i < preFix.size()-1; ++i){
            res.push_back(preFix[i]*sufFix[sufFix.size()-i-2]);
        }

        return res;
    }
};