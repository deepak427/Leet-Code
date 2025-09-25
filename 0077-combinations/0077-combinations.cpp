class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& combinations, vector<int>& curr, int index,
                   int& targetSize) {
        if (curr.size() == targetSize) {
            res.push_back(curr);
            return;
        }

        for (int i = index; i < combinations.size(); ++i) {
            curr.push_back(combinations[i]);
            backtrack(combinations, curr, ++index, targetSize);
            curr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> numbers;
        for (int i = 1; i <= n; ++i) {
            numbers.push_back(i);
        }

        vector<int> currentPass;
        backtrack(numbers, currentPass, 0, k);
        return res;
    }
};