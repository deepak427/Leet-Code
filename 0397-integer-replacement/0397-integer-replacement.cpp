class Solution {
public:
    int integerReplacement(int n) {
        long long ln = n;
        int ops = 0;
        while(ln>1){
            ++ops;
            if(ln%2==0) ln/=2;
            else if((ln/2)%2==0 || ln==3) ln-=1;
            else ln+=1;
        }

        return ops;
    }
};