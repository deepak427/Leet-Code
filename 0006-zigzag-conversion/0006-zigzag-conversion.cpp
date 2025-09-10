class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int distance = (2 * numRows) - 2;
        string res = "";

        for (int i = 0; i < numRows; ++i) {
            for (int k = i; k < s.length(); k += distance) {
                res += s[k];
                if(k+2*(numRows-i-1)<s.length() && i!=0 && i!=numRows-1){
                    res+=s[k+2*(numRows-i-1)];
                }
            }
        }
        return res;
    }
};