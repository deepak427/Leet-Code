class Solution {
public:
    int nonSpecialCount(int l, int r) {
        int n = sqrt(r);

        vector<bool> v(n+1, 1);
        v[0] = 0;
        v[1] = 0;

        int result = 0;

        for(int i =2; i <= n; ++i){
            if(v[i]){
                int squared = i*i;
                if((squared >= l) && (squared <= r)){
                    result++;
                }

                for(int j = i*i; j <=n; j+=i){
                    v[j] = 0;
                }
            }
        }

        return ((r-l+1) - result);
    }
};