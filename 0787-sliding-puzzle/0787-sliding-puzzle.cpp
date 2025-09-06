class Solution {
public:
    pair<int, int> onedTo2d(int pos) { return {pos / 3, pos % 3}; }

    int twodTo1d(pair<int, int> pos) { return 3 * pos.first + pos.second; }

    vector<pair<int, int>> getNeighbours(pair<int, int> pos) {
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        vector<pair<int, int>> neighbours;
        for (pair<int, int>& dir : directions) {
            int x = pos.first + dir.first;
            int y = pos.second + dir.second;
            if (x >= 0 && x < 2 && y >= 0 && y < 3)
                neighbours.push_back({x, y});
        }

        return neighbours;
    }

    int find0(string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '0')
                return i;
        }
        return -1;
    }

    vector<string> getPuzzleNeighbours(string s) {
        int pos = find0(s);
        pair<int, int> twodPos = onedTo2d(pos);
        vector<pair<int, int>> twodNeighbours = getNeighbours(twodPos);
        vector<int> onedNeighbours;
        for (pair<int, int>& n : twodNeighbours) {
            onedNeighbours.push_back(twodTo1d(n));
        }

        vector<string> neighbours;
        for (int& n : onedNeighbours) {
            string temp = s;
            char a = temp[pos];
            temp[pos] = temp[n];
            temp[n] = a;
            neighbours.push_back(temp);
        }

        return neighbours;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        string root = "";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                root += board[i][j] + '0';
            }
        }

        queue<string> q;
        q.push(root);
        unordered_set<string> visited;
        visited.insert(root);

        int steps = 0;
        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; ++i) {
                string curr = q.front();
                q.pop();
                if (curr == "123450")
                    return steps;

                for (string& n : getPuzzleNeighbours(curr)) {
                    if (visited.find(n) == visited.end()) {
                        visited.insert(n);
                        q.push(n);
                    }
                }
            }
            ++steps;
        }

        return -1;
    }
};