class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> um;
        for (char c : s) {
            ++um[c];
        }

        int pairs = 0;
        int single = 0;
        for (auto p : um) {
            if (!single && p.second % 2 == 1)
                single = 1;
            pairs += p.second / 2;
        }

        return single + pairs * 2;
    }
};