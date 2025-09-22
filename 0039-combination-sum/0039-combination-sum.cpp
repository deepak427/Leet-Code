class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& candidates, vector<int>& currentPath,
                   int& currentSum, int& target) {
        if (currentSum >= target) {
            vector<int> sortedPath = currentPath;
            sort(sortedPath.begin(), sortedPath.end());
            if (currentSum == target &&
                find(res.begin(), res.end(), sortedPath) == res.end())
                res.push_back(sortedPath);
            return;
        }

        for (int& cand : candidates) {
            currentPath.push_back(cand);
            currentSum += cand;
            backtrack(candidates, currentPath, currentSum, target);
            currentPath.pop_back();
            currentSum -= cand;
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currentPath = {};
        int sum = 0;
        backtrack(candidates, currentPath, sum, target);
        return res;
    }
};