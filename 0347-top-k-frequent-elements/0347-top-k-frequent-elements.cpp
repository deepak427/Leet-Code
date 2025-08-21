class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequency;
        for(int i = 0; i < nums.size(); ++i){
            frequency[nums[i]]++;
        }
        priority_queue<pair<int,int>> heap;
        vector<int> res;
        for(pair<int, int> element: frequency){
            heap.push({element.second, element.first});
            if(heap.size()>frequency.size()-k){
                res.push_back(heap.top().second);
                heap.pop();
            }
        }

        return res;
    }
};