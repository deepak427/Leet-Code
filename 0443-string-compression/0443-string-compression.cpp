class Solution {
public:
    int compress(vector<char>& chars) {
        int start = 0;
        unordered_map<char, int> um;
        int count = 1;

        for (int end = 1; end < chars.size(); ++end) {
            if (chars[end] == chars[end - 1])
                ++count;
            else {
                if (count > 1) {
                    for (char c : to_string(count))
                        chars[++start] = c;
                }
                chars[++start] = chars[end];
                count = 1;
            }
        }

        ++start;
        if (count > 1) {
            for (char c : to_string(count))
                chars[start++] = c;
        }

        return start;
    }
};