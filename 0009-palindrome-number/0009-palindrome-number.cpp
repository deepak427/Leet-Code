class Solution {
public:
    bool isPalindrome(int x) {
        string xString = "";
        if (x < 0)
            xString += '-';
        while (x % 10 != x) {
            int digit = x % 10;
            xString += '0' + digit;
            x /= 10;
        }
        xString += '0' + x;
        int start = 0, end = xString.length() - 1;
        while (start < end) {
            if (xString[start++] != xString[end--])
                return false;
        }
        return true;
    }
};