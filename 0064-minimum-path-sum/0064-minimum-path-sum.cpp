class Solution {
public:
    struct Compare {
        bool operator()(vector<int> const& a, vector<int> const& b) {
            return a[2] > b[2];
        }
    };

    int minPathSum(vector<vector<int>>& grid) {
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;

        pq.push({0, 0, 0});
        vector<int> distances(grid.size() * grid[0].size(), INT_MAX);
        distances[0] = 0;

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            if (curr[0] == (grid.size() - 1) && curr[1] == (grid[0].size() - 1))
                return curr[2]+grid[0][0];

            vector<vector<int>> directions = {{0, 1}, {1, 0}};
            for (vector<int>& dir : directions) {
                int x = curr[0] + dir[0];
                int y = curr[1] + dir[1];
                if (x < grid.size() && y < grid[0].size()) {
                    int currDistance = curr[2] + grid[x][y];
                    if (currDistance < distances[(grid[0].size() * x) + y]) {
                        distances[(grid[0].size() * x) + y] = currDistance;
                        pq.push({x, y, currDistance});
                    }
                }
            }
        }

        return -1;
    }
};