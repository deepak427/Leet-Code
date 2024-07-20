class Solution {
public:
        vector<int> shortestToChar(string S, char C) {
            vector<int> result(S.size());
            int pos = -S.size();

            for(int i =0; i< S.size(); ++i){
                if(S[i] == C){
                    pos = i;
                }
                result[i] = i-pos;
            }

            for(int i = (pos-1); i > -1; --i){
                if(S[i] == C){
                    pos = i;
                    continue;
                }
                result[i] = min(pos-i, result[i]);                
            }

        return result;
    }
};