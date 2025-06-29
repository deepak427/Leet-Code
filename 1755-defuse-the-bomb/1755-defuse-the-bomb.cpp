class Solution {
public:
    int sum(int start, int end, vector<int> &code){
        long sum = 0;

        if(start == end){
            return code[start];
        }

        if(end > start){
            for(int i = start; i <= end; ++i){
                sum = sum + code[i];
            }

            return sum;
        }

        for(int i = start; i < code.size(); ++i){
            sum = sum + code[i];
        }

        for(int i = 0; i <= end; ++i){
            sum = sum + code[i];
        }

        return sum;
    }

    vector<int> decrypt(vector<int>& code, int k) {
        if(k == 0){
            vector<int> c_copy(code.size(), 0);
            return c_copy;
        }
        int iterator = 0;
        int start;
        int end; 

        if(k > 0){
            start = 1;
            end = (start+k-1) % code.size();
        }else{
            end = code.size()-1;
            start = end+k+1;
        }

        vector<int> copy = code;

        while(iterator < code.size()){
            code[iterator] = sum(start,end, copy);
            start = (start+1) % code.size();
            end = (end+1) % code.size();

            ++iterator;
        }

        return code;
    }
};