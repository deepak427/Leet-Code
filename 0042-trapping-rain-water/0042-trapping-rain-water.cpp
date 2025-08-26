class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size(), height[0]);
        for (int i = 1; i < height.size(); ++i) {
            prefix[i] = max(height[i], prefix[i - 1]);
        }
        vector<int> suffix(height.size(), height[height.size() - 1]);
        for (int i = height.size() - 2; i >= 0; --i) {
            suffix[i] = max(height[i], suffix[i + 1]);
        }

        int trapped = 0;
        for (int i = 1; i < prefix.size()-1; ++i) {
            trapped += max(min(prefix[i], suffix[i]) - height[i], 0);
        }

        return trapped;
    }
};