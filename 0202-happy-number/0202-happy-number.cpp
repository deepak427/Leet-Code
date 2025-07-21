class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> us;

        while(us.find(n) == us.end()){
            us.insert(n);
            int sum = 0;
            while(n!=n%10){
                sum+=(n%10)*(n%10);
                n/=10;
            }
            sum+=n*n;
            if(sum==1) return true;
            n=sum;
        }

        return false;
    }
};