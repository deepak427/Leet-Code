class Solution {
public:
    int numberOfSubstrings(string s) {
        int start = 0, output = 0;
        unordered_map<char, int> um;

        for(int end = 0; end < s.length(); ++end){
            ++um[s[end]];
            if(um.size() == 3){
                output = output + (s.length()-end);
                while(um.size() == 3){
                    if(--um[s[start]] == 0){
                        um.erase(s[start]);
                        start++;
                        break;
                    }
                    ++start;
                    output = output + (s.length()-end);
                }
            }
        }

        return output;
    }
};