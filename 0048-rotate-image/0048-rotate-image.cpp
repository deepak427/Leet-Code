class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size()-1;
        int start = 0;

        while(start<=n/2){
            pair<int, int> a = {start, start};
            pair<int, int> b = {start, n-start};
            pair<int, int> c = {n-start, n-start};
            pair<int, int> d = {n-start, start};

            for(int i = start; i < n-start; ++i){
                int tempB = matrix[b.first][b.second];
                int tempC = matrix[c.first][c.second];
                int tempD = matrix[d.first][d.second];
                matrix[b.first++][b.second] = matrix[a.first][a.second];
                matrix[c.first][c.second--] = tempB;
                matrix[d.first--][d.second] = tempC; 
                matrix[a.first][a.second++] = tempD;
            }
            ++start;
        }
    }
};