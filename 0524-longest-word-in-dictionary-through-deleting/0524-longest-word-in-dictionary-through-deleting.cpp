class Solution {
public:
    bool isSubstring(string toCheck, string fromCheck) {
        int p1 = 0, p2 = 0;
        while (p2 < fromCheck.length()) {
            if (toCheck[p1] == fromCheck[p2]) {
                if (++p1 == toCheck.length())
                    return true;
                ++p2;
            }
            else {
                ++p2;
            }
        }

        return false;
    }
    string findLongestWord(string s, vector<string>& dictionary) {
        string res = "";
        sort(dictionary.begin(), dictionary.end());

        for (string str : dictionary) {
            if (isSubstring(str, s) && str.length() > res.length())
                res = str;
        }

        return res;
    }
};