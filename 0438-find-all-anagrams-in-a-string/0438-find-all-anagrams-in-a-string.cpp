class Solution {
public:
    bool matchStrings(unordered_map<char, int> s1,
                      unordered_map<char, int> s2) {
        for (auto& elem : s1) {
            if (s2.find(elem.first) == s2.end())
                return false;
            if (s2[elem.first] != elem.second)
                return false;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> p_mp;
        for (char& c : p) {
            ++p_mp[c];
        }

        unordered_map<char, int> s_mp;
        int start = 0;
        for (int i = 0; i < s.length(); ++i) {
            ++s_mp[s[i]];
            if (i < p.length() - 1)
                continue;
            if (matchStrings(p_mp, s_mp))
                res.push_back(start);
            --s_mp[s[start++]];
        }
        return res;
    }
};