class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> um;
        for(string &word: strs){
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());
            um[sortedWord].push_back(word);
        }

        vector<vector<string>> res;
        for(auto &pair: um){
            res.push_back(pair.second);
        }

        return res;
    }
};