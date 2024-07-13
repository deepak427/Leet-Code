class Solution {
public:
     vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> result; 
        for(int i = 0; i < grid[0].size(); ++i){
            result.push_back(i);
        }
        for(auto &row: grid){
            for(auto &cell: result){
                if( cell != -1){
                    if( cell+row[cell] == result.size() ||  cell+row[cell] == -1){
                        cell = -1;              
                    }
                    else {
                        if(row[cell] == row[ cell+row[cell]]){
                            cell = cell + row[cell];
                        }else {
                            cell = -1;
                        }
                    }
                }
            }
        }
        
        return result;
    }
};