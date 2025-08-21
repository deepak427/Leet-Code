class Solution {
public:
    string frequencySort(string s) {
        string res = "";

        unordered_map<int, int> frequency;
        for(char &c: s){
            ++frequency[c];
        }
        priority_queue<pair<int, int>> maxHeap;
        for(auto &f: frequency){
            maxHeap.push({f.second, f.first});
        }

        while(!maxHeap.empty()){
            string s(maxHeap.top().first, maxHeap.top().second);
            res+=s;
            maxHeap.pop();
        }
        return res;
    }
};