class Solution {
public:
     vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> result; 
        for(int i = 0; i < grid[0].size(); ++i){
            result.push_back(i);
        }
        for(auto &row: grid){
            for(int j = 0; j < result.size(); ++j){
                if( result[j] != -1){
                    if( result[j]+row[result[j]] == result.size() ||  result[j]+row[result[j]] == -1){
                        result[j] = -1;              
                    }
                    else {
                        if(row[result[j]] == row[ result[j]+row[result[j]]]){
                            result[j] = result[j] + row[result[j]];
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