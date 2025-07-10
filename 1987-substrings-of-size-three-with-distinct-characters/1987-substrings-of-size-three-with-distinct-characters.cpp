class Solution {
public:
    int countGoodSubstrings(string s) {
        int start = 0, g_strings = 0;
        unordered_map<char, int> u_m;   

        for(int end = 0; end < s.length(); ++end){
            ++u_m[s[end]];
            while(u_m[s[end]] > 1){
                if(--u_m[s[start]] == 0){
                    u_m.erase(s[start]);
                }
                ++start;
            }

            if(end-start == 2){
                ++g_strings;
                if(--u_m[s[start]] == 0){
                    u_m.erase(s[start]);
                }
                ++start;
            }
        }

        return g_strings;
    }
};