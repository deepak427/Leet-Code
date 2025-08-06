class Solution {
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int end = num.length() - 1;

        for (int i = num.length() - 2; i >= 0; --i) {
            if (num[i] < num[i + 1]) {
                while (num[end] <= num[i])
                    --end;
                swap(num[i], num[end]);
                int start = i + 1, end = num.length() - 1;
                while (start < end) {
                    swap(num[start++], num[end--]);
                }
                return stol(num) > INT_MAX ? -1 : stoi(num);
            }
        }

        return -1;
    }
};