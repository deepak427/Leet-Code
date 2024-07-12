class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> char_map;

        for(char &c: s){
            char_map[c]++;
        }

        for (int i = 0; i< s.size(); ++i) {
            if(char_map.find(s[i])->second == 1){
                return i;
            }
        }

        return -1;
    }
};