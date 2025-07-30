class Solution {
public:
    bool judgeSquareSum(int c) {
        int i = 0, j = static_cast<int>(sqrt(c));
        while (i <= j) {
            long long sSum = 1LL * i * i + j * j;
            if (sSum == c)
                return true;
            else if (sSum < c)
                ++i;
            else
                --j;
        }
        return false;
    }
};