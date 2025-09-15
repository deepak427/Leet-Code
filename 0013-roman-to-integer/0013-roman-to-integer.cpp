class Solution {
public:
    int romanToInt(string s) {
        vector<char> symbol = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        vector<int> value = {1, 5, 10, 50, 100, 500, 1000};

        int result = 0;

        int lastPos = 7;
        for (char& c : s) {
            auto itt = find(symbol.begin(), symbol.end(), c);
            int it = itt - symbol.begin();
            int charValue = value[it];
            if (it > lastPos)
                result += charValue - (2 * value[lastPos]);
            else {
                result += charValue;
                lastPos = it;
            }
        }
        return result;
    }
};