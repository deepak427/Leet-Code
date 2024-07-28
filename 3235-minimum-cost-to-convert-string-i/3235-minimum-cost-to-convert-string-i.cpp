class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int noOfChars = 26;
        #define INF 1e9
        vector<vector<int>> graph(26, vector<int>(26,INF));

        if(source == target){
            return 0;
        }

        for(int i = 0;i < 26; ++i){
            graph[i][i] = 0;
        }

        for(int i =0; i< original.size(); ++i){
            int intValueOrignal = original[i] - 'a';
            int intValueChanged = changed[i] - 'a';

            graph[intValueOrignal][intValueChanged] = min(cost[i],graph[intValueOrignal][intValueChanged]);
        }

        for(int i = 0; i < noOfChars; ++i){
            for(int j = 0; j < noOfChars; ++j){
                if(graph[j][i] < INF){
                    for(int k =0; k < noOfChars; ++k){
                        int intermediateCost = graph[j][i] + graph[i][k];
                        if(intermediateCost < graph[j][k]){
                            graph[j][k] = intermediateCost;
                        }
                    }
                }
            }
        }

        long long costResult = 0;

        for(int i = 0; i < source.size(); ++i){
            int intValue = source[i] - 'a';
            int intValueTarget = target[i] - 'a';
            if(intValue != intValueTarget){
                if(graph[intValue][intValueTarget] != INF){
                    costResult = costResult + graph[intValue][intValueTarget];
                }else {
                    return -1;
                }
            }
        }

        return costResult;

    }
};