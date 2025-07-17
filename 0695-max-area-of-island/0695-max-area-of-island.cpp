class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int max_area = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    int c_area = 0;
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty()) {
                        int sz = q.size();

                        for (int k = 0; k < sz; ++k) {
                            pair<int, int> curr = q.front();
                            q.pop();
                            ++c_area;
                            grid[curr.first][curr.second] = 0;

                            for (pair<int, int> dir : directions) {
                                int x = curr.first + dir.first;
                                int y = curr.second + dir.second;
                                if (x >= 0 && x < grid.size() && y >= 0 &&
                                    y < grid[0].size() && grid[x][y] != 0) {
                                    q.push({x, y});
                                    grid[x][y] = 0;
                                }
                            }
                        }
                    }

                    max_area = max(max_area, c_area);
                }
            }
        }

        return max_area;
    }
};