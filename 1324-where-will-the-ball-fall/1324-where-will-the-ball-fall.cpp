class Solution {
public:
     vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> result; 
        for(int i = 0; i < grid[0].size(); ++i){
            result.push_back(i);
        }
        for(int i = 0; i < grid.size(); ++i){
            for(int j = 0; j < result.size(); ++j){
                if( result[j] != -1){
                    int next = result[j]+grid[i][result[j]];
                    if(next == result.size() || next == -1){
                        result[j] = -1;              
                    }
                    else {
                        if(grid[i][result[j]] == grid[i][next]){
                            result[j] = result[j] + grid[i][result[j]];
                        }else {
                            result[j] = -1;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};