class Solution {
public:
    int magicalString(int n) {
        string magical = "122";
        int p1 = 2;
        int p2 = 2;

        int count = 1;

        while (magical.length() < n) {
            char val = magical[p2] == '1' ? '2' : '1';
            for (int i = 0; i < magical[p1]-'0'; ++i) {
                if(val=='1') ++count;
                magical += val;
                ++p2;
                if(magical.length()==n) return count;
            }
            ++p1;
        }

        return count;
    }
};