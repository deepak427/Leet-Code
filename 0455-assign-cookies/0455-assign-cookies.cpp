class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gp = 0, sp = 0;
        int contented = 0;

        while (gp < g.size() && sp < s.size()) {
            if (g[gp] <= s[sp]) {
                ++contented;
                ++gp;
                ++sp;
            }else ++sp;
        }

        return contented;
    }
};