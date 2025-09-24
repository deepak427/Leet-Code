class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int> currentPass) {
        if (currentPass.size() == nums.size()) {
            res.push_back(currentPass);
            return;
        }

        for (int& num : nums) {
            if (find(currentPass.begin(), currentPass.end(), num) !=
                currentPass.end())
                continue;
            currentPass.push_back(num);
            backtrack(nums, currentPass);
            currentPass.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currentPass = {};
        backtrack(nums, currentPass);
        return res;
    }
};