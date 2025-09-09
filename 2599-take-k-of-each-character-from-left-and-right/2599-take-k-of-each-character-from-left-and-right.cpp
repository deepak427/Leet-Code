class Solution {
public:
    int takeCharacters(string s, int k) {
        unordered_map<char, int> freMap;
        for (char& c : s) {
            ++freMap[c];
        }
        freMap['a'] -= k;
        freMap['b'] -= k;
        freMap['c'] -= k;
        if (freMap['a'] < 0 || freMap['b'] < 0 || freMap['c'] < 0)
            return -1;

        int start = 0, maxLen = 0;
        unordered_map<char, int> um;
        for (int i = 0; i < s.length(); ++i) {
            ++um[s[i]];
            while (um[s[i]] > freMap[s[i]]) {
                --um[s[start++]];
            }
            maxLen = max(maxLen, i - start + 1);
        }

        return s.length() - maxLen;
    }
};