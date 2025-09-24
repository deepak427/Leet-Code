class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, vector<int> currentPass,
                   unordered_set<int> currentPassSet) {
        if (currentPass.size() == nums.size()) {
            res.push_back(currentPass);
            return;
        }

        for (int& num : nums) {
            if (currentPassSet.find(num)!=currentPassSet.end())
                continue;
            currentPass.push_back(num);
            currentPassSet.insert(num);
            backtrack(nums, currentPass, currentPassSet);
            currentPass.pop_back();
            currentPassSet.erase(num);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> currentPass = {};
        unordered_set<int> currentPassSet;
        backtrack(nums, currentPass, currentPassSet);
        return res;
    }
};