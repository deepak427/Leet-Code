class Solution {
public:
    vector<int> shortestToChar(string &s, char &c) {

        vector<int> answer(s.size());

        int start = 0;

        size_t found = s.find(c, start);
        if (found != string::npos){
            for(int i = start; i <= found; ++i){
                answer[i] = found-i;
            }
            start = found+1;
        }

        while(start < s.size()){
            found = s.find(c, start);
            if (found != string::npos){
                for(int i = start; i <= found; ++i){
                    if((found-i) < (i-(start-1))){
                        answer[i] = found-i;
                    }else{
                        answer[i] = i-(start-1);
                    }
                }
                start = found+1;
            }else{
                 for(int i = start; i < s.size(); ++i){
                    answer[i] = i-(start-1);
                }     
                break;          
            }
        }

        return answer;
    }
};