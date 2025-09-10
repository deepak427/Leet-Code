class Solution {
public:
    bool isPalindrome(int i, int j, string& s) {
        while (i < j) {
            if (s[i++] != s[j--])
                return false;
        }

        return true;
    }

    string longestPalindrome(string s) {
        string longestPalindrom;

        for (int i = 0; i < s.length(); ++i) {
            for (int j = i; j < s.length(); ++j) {
                if ((j - i + 1) > longestPalindrom.length() &&
                    isPalindrome(i, j, s))

                    longestPalindrom = s.substr(i, j - i + 1);
            }
        }

        return longestPalindrom;
    }
};