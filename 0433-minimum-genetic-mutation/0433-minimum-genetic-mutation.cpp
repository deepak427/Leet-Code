class Solution {
public:
    vector<string> getNeighbours(string s, vector<string> &bank){
        vector<string> neighbours;

        for(string string_b: bank){
            int changed = 0;
            for(int c = 0; c < string_b.length(); ++c){
                if(string_b[c] != s[c]) ++changed;
            }
            if(changed == 1) neighbours.push_back(string_b);
        }

        return neighbours;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        q.push(startGene);
        unordered_map<string, int> visited;
        ++visited[startGene];

        int level = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; ++i){
                string curr = q.front(); q.pop();

                if(curr == endGene){
                    return level;
                }

                
                for(auto n: getNeighbours(curr, bank)){
                    if(visited.find(n) == visited.end()){
                        q.push(n);
                        ++visited[n];
                    }
                }
                
            }

            ++level;
        }

        return -1;
    }
};