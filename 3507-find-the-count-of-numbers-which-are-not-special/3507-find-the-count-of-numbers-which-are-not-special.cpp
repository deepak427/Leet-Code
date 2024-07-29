class Solution {
public:
    int nonSpecialCount(int l, int r) {
        vector<bool> v(sqrt(r)+1, 1);
        v[0] = 0;
        v[1] = 0;

        int result = 0;

        for(int i =2; i <= sqrt(r); ++i){
            if(v[i]){
                int squared = i*i;
                if((squared >= l) && (squared <= r)){
                    result++;
                }

                for(int j = i*i; j <=sqrt(r); j+=i){
                    v[j] = 0;
                }
            }
        }

        return ((r-l+1) - result);
    }
};