class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        sort(arrays.begin(), arrays.end());
        int max_d = INT_MIN;
        int min_d = arrays[0][0];
        for(int i = 1; i < arrays.size(); ++i){
            max_d = max(max_d, abs(arrays[i][arrays[i].size()-1]-min_d));
        }

        return max(max_d, abs(arrays[1][0]-arrays[0][arrays[0].size()-1]));
    }
};