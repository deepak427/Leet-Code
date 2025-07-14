class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        queue<int> q;

        unordered_set<int> visited;

        int provinces = 0;

        for (int node = 0; node < isConnected.size(); ++node) {
            if (visited.find(node) == visited.end()) {
                visited.insert(node);
                q.push(node);
                while (!q.empty()) {
                    int sz = q.size();

                    for (int i = 0; i < sz; ++i) {
                        int curr = q.front();
                        q.pop();

                        for (int n = 0; n < isConnected[curr].size(); ++n) {
                            if (isConnected[curr][n] == 1 && n != curr &&
                                visited.find(n) == visited.end()) {
                                q.push(n);
                                visited.insert(n);
                            }
                        }
                    }
                }

                ++provinces;
            }
        }

        return provinces;
    }
};