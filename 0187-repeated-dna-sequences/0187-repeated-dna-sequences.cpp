class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> char_map;

        vector<string> result;

        if(s.size() < 10){
            return result;
        }

        for(int i = 0; i< s.size() - 9; ++i){
            string substring = s.substr(i, 10);
            char_map[substring]++;        
        }

        for( auto &value: char_map) {
            if(value.second > 1){
                result.push_back(value.first);
            }
        }

        return result;
    }
};