class Solution {
public:
    int lengthOfLongestSubstring(string &s) {
        if(s.size() == 1) return 1;
        if(s.size() == 0) return 0;

        int start = 0;
        int end = 1;

        int output = 1;
        string s_string;

        while(end < s.size()){
            s_string = s.substr(start, end - start);

            size_t index = s_string.find(s[end]);

            if(index != string::npos){
                start = start + index + 1;
            }else{
                if((s_string.size()+1) > output){
                    output = s_string.size() + 1;
                }
            }

            ++end;
        }

        return output;
    }
};