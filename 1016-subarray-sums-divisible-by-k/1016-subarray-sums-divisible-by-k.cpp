class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum = 0;
        int count = 0;

        m[0] = 1;

        if(nums.size() == 0){
            return 0;
        }

        for(int i: nums){
            sum = sum + i;
            int mod = sum%k;

            if(mod < 0){
                mod = mod +k;
            }

            if(m.find(mod) != m.end()){
                count = count+m[mod];
            }

            m[mod]++;
        }

        return count;
    }
};