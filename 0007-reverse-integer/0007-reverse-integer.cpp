class Solution {
public:
    int reverse(int x) {
        string strNum = "";
        bool isNegative = false;
        string posMax = "2147483647";
        string negMin = "2147483648";

        if (x < 0) {
            isNegative = true;
        }
        while (x % 10 != x) {
            int mod = x % 10;
            if(mod<0) mod*=-1;
            strNum += '0' + mod;
            x /= 10;
        }
        if(x<0) x*=-1;
        strNum += '0'+x;
        if(isNegative && strNum.length()>9 && strNum>negMin) return 0;
        if(!isNegative && strNum.length()>9 && strNum>posMax) return 0;

        if(isNegative) return -1*stoi(strNum);
        return stoi(strNum);
    }
};