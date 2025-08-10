class Solution {
public:
    unordered_set<int> visited;
    void dfs(vector<vector<int>>& rooms, int room = 0){
        for(int key: rooms[room]){
            if(visited.find(key)==visited.end()){
                visited.insert(key);
                dfs(rooms, key);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        visited.insert(0);
        dfs(rooms);
        return visited.size()==rooms.size();
    }
};