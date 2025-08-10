class Solution {
public:
    void dfs(int src, vector<vector<int>>& graph, vector<vector<int>>& paths,
             vector<int> cPath) {
        cPath.push_back(src);
        for (auto& n : graph[src]) {
            dfs(n, graph, paths, cPath);
        }
        if (src == graph.size() - 1)
            paths.push_back(cPath);
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> cPath;
        dfs(0, graph, paths, cPath);
        return paths;
    }
};